#include "checkers.hpp"

int Checkers::sLAYOUT[17] = {
    1, 2, 3, 4, 13, 12, 11, 10, 9, 
    10, 11, 12, 13, 4, 3, 2, 1
};

int Checkers::sINDICES[17] = {
    0, 1, 3, 6, 10, 23, 35, 46, 56,
    65, 75, 86, 98, 111, 115, 118, 120,
};

Checkers::Checkers(sf::RenderWindow& win, sf::Color& fill) {
    mTurn = true;
    mWin = &win;
    mFill = &fill;
    mSelected = nullptr;
    mEnableMouse = true;

    config();   
    resetBoard();
}

void Checkers::switchTurn() {
    mTurn = !mTurn;
    // rotateBoard();
    mEnableMouse = true;
}

bool Checkers::movedAtAll() {
    if (!mEnableMouse) {
        if (mSelected != nullptr) mSelected->resetFill();
        return true;
    }
    return false;
}

void Checkers::draw() const {
    mWin->clear(*mFill);
    mWin->draw(mOutline);
    for (auto& s : mSlots) {
        mWin->draw(s, mTrans);
        mWin->draw(s.mOverlay, mTrans);
    }
    mWin->display();
}

void Checkers::rotateBoard() {
    int rotation = 0;
    sf::Clock c;
    while (rotation < 180) {
        if (c.getElapsedTime().asMilliseconds() >= 4) {
            mTrans.rotate(1, mCENTER);
            draw();
            c.restart();
            rotation++;
        }
    }
}

void Checkers::resetBoard() {
    float x;
    float y = 2 * GAP + RADIUS;
    sf::Color* colorStepper = &mColors[0];
    int rowCount;

    int guide[20] = {0,0,0,0,-1,2,3,3,4,5,-2,4,3,3,2,-2,0,0,0,0};
    int* guidePtr = &guide[0];

    for (int i = 0; i < 17; i++) {
        rowCount = sLAYOUT[i];
        if (*guidePtr < 0) {
            colorStepper += abs(*guidePtr);
            guidePtr++;
        }
        x = HEIGHT / 2;
        if (rowCount % 2 == 0) 
            x -= (RADIUS + GAP / 2.f);
        else {
            if (rowCount > 4) 
                mSlots.push_back(Slot(x, y, *mFill));
            else              
                mSlots.push_back(Slot(x, y, *colorStepper));
            x -= STEP;
        }       
        for (int j = 0; j < rowCount / 2; j++) {
            if (j >= *guidePtr) {
                mSlots.push_back(Slot(x, y, *colorStepper));
                if (rowCount > 4)
                    mSlots.push_back(Slot(HEIGHT - x, y, *(colorStepper+1)));
                else
                    mSlots.push_back(Slot(HEIGHT - x, y, *colorStepper));
            }
            else {
                mSlots.push_back(Slot(x, y, *mFill));
                mSlots.push_back(Slot(HEIGHT - x, y, *mFill));
            }
            x -= STEP;
        }
        y += STEP;
        guidePtr++;
    }
}

void Checkers::processClick(float x, float y, bool force) {
    Slot* clicked = find(x, y);
    if (clicked == nullptr) 
        return;
    int id = getIdentity(clicked);
    if (force || (id == mTurn && mEnableMouse)) {
        if (mSelected != nullptr) 
            mSelected->resetFill();
        clicked->pick();
        mSelected = clicked;
    }
    else if (id == -1 && mSelected != nullptr) {
        int moveType = validateMove(clicked, mSelected);
        sf::Vector2f pos = mSelected->getPosition();
        if (moveType == 0) 
            return;
        bool ender = moveType == 1 || !foundLegal(pos.x, pos.y);
        if (mEnableMouse || !ender) {
            clicked->setFillColor(mSelected->getFillColor());
            clicked->resetFill();

            mSelected->setFillColor(*mFill);
            mSelected->resetFill();
            if (mEnableMouse && ender) {
                mSelected = nullptr;
                switchTurn();
            }
            else if (moveType == 2) {
                mEnableMouse = false;
                processClick(x, y, true);
            }
        }
    }
}

bool Checkers::foundLegal(float x, float y) {
    float length = RADIUS * 4;
    float nx, ny;
    for (int angle = 0; angle < 360; angle += 60) {
        nx = x + length * cosf(angle * RADIAN);
        ny = y + length * sinf(angle * RADIAN);
        Slot* temp = find(nx, ny);
        if (temp != nullptr && getIdentity(temp) == -1)
            return true;
    }
    return false;
}

Slot* Checkers::find(float x, float y) {
    int row = static_cast<int>((y - RADIUS + THICK) / STEP);
    for (int i = sINDICES[row]; i < sINDICES[row+1]; i++) {
        Slot* curr = &mSlots[i];
        if (curr->clicked(x, y))
            return curr;
    }
    return nullptr;
}

int Checkers::getIdentity(const Slot* slot) {
    sf::Color fill = slot->getFillColor();
    if (fill == *mFill) return -1;
    // FIRST 3 -> return 0
    // ELSE    -> return 1
    return (fill == mColors[3] || fill == mColors[4] || fill == mColors[5]);
}

int Checkers::validateMove(const Slot* s1, const Slot* s2) {
    sf::Vector2f s1pos = s1->getPosition();
    sf::Vector2f s2pos = s2->getPosition();

    float distance = sqrtf(powf(s1pos.y - s2pos.y, 2) + powf(s1pos.x - s2pos.x, 2));    
    if (distance <= 4 * RADIUS)
        return 1;

    // MIDPOINT
    float midX = (s1pos.x + s2pos.x) / 2.f;
    float midY = (s1pos.y + s2pos.y) / 2.f;
    auto midPoint = find(midX, midY);
    if (midPoint != nullptr && getIdentity(midPoint) != -1)
        return 2;
    return 0;
}

void Checkers::config() {
    mOutline.setPosition(mCENTER);
    mOutline.setFillColor(*mFill);
    mOutline.setRadius(BOARD_DIAMETER / 2);
    mOutline.setOutlineColor(sf::Color::Black);
    mOutline.setOutlineThickness(THICK);
    mOutline.setPointCount(mOutline.getPointCount() * 2);
    mOutline.setOrigin(mOutline.getRadius(), mOutline.getRadius());

    // FIRST 3 -> mTurn = FALSE
    // LAST  3 -> mTurn = TRUE
    mColors.reserve(6);
    mColors.push_back(sf::Color::White);
    mColors.push_back(sf::Color::Red);
    mColors.push_back(sf::Color::Blue);
    mColors.push_back(sf::Color::Green);
    mColors.push_back(sf::Color::Yellow);
    mColors.push_back(sf::Color(90, 90, 90));
}