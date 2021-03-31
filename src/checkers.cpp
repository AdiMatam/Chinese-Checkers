#include "Checkers.hpp"

int Checkers::sLAYOUT[17] = {
    1, 2, 3, 4, 13, 12, 11, 10, 9, 
    10, 11, 12, 13, 4, 3, 2, 1
};


Checkers::Checkers(sf::RenderWindow& win, sf::Color& fill) {
    mTurn = true;
    mWin = &win;
    mFill = &fill;
    mRotation = 0;
    mSelected = nullptr;

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
    
    reset();
    if (mSlots.size() != 121) printf("Actual Slot Count: %d\n", mSlots.size());
}
void Checkers::draw() const {
    mWin->draw(mOutline);
    for (auto& s : mSlots) {
        mWin->draw(s, mTrans);
        mWin->draw(s.mOverlay);
    }
}

void Checkers::rotateBoard() {
    if (++mRotation == 181) 
        mRotation = 0;
    else 
        mTrans.rotate(1, mCENTER);
}

void Checkers::reset() {
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

void Checkers::processClick(float x, float y) {
    Slot* clicked = find(x, y);
    if (clicked == nullptr) return;
    int id = getIdentity(clicked);
    if (id == getTurn()) {
        if (mSelected != nullptr) 
            mSelected->resetFill();
        clicked->pick();
        mSelected = clicked;
    }
    else if (id == -1 && mSelected != nullptr && validateMove(clicked, mSelected)) {
        clicked->setFillColor(mSelected->getFillColor());
        clicked->resetFill();

        mSelected->setFillColor(*mFill);
        mSelected->resetFill();
        mSelected = nullptr;
        switchTurn();
    }
}

Slot* Checkers::find(float x, float y) {
    for (Slot& s : mSlots) {
        if (s.clicked(x, y))
            return &s;
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

bool Checkers::validateMove(const Slot* s1, const Slot* s2) {
    sf::Vector2f s1pos = s1->getPosition();
    sf::Vector2f s2pos = s2->getPosition();

    float distance = sqrtf(powf(s1pos.y - s2pos.y, 2) + powf(s1pos.x - s2pos.x, 2));    
    if (distance <= 4 * RADIUS)
        return true;

    // MIDPOINT
    float midX = (s1pos.x + s2pos.x) / 2.f;
    float midY = (s1pos.y + s2pos.y) / 2.f;
    auto midPoint = find(midX, midY);
    return midPoint != nullptr && getIdentity(midPoint) != -1;
}

bool Checkers::getTurn() const {
    return mTurn;
}
void Checkers::switchTurn() {
    mTurn = !mTurn;
}
const sf::Color& Checkers::getFill() const {
    return *mFill;
}
void Checkers::setFill(sf::Color& fill) {
    mFill = &fill;
}
std::vector<Slot>& Checkers::getSlots() {
    return mSlots;
}
int Checkers::getRotation() const {
    return mRotation;
}
const Slot* Checkers::getSelected() const {
    return mSelected;
}