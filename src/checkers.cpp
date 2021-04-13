#include "pch.hpp"
#include "checkers.hpp"

//int Checkers::sINDICES[18] = {
//    0, 1, 3, 6, 10, 23, 35, 46, 56,
//    65, 75, 86, 98, 111, 115, 118, 120, 121
//};

Checkers::Checkers(sf::RenderWindow& win, sf::Color& fill)
    : mWin(&win), mFill(&fill), mTurn(true), mSelected(nullptr), mEnableMouse(true)
{
    config();   
    resetBoard();
}

void Checkers::switchTurn() {
    mTurn = !mTurn;
    rotateBoard();
    mEnableMouse = true;
}

bool Checkers::movedAtAll() {
    if (!mEnableMouse) {
        if (mSelected != nullptr) 
            mSelected->resetFill();
        return true;
    }
    return false;
}

void Checkers::draw() const {
    mWin->clear(*mFill);
    mWin->draw(mOutline);
    for (auto& s : mSlots) {
        mWin->draw(s, mTrans);
        mWin->draw(s.overlay, mTrans);
    }
    mWin->display();
}

void Checkers::rotateBoard() {
    int rotation = 0;
    sf::Clock c;
    int delay = 400;
    while (rotation < 180) {
        draw();
        if (c.getElapsedTime().asMilliseconds() >= delay) {
            rotation++;
            mTrans.rotate(1, mCENTER);
            c.restart();
            delay = 4;
        }
    }
}


void Checkers::processClick(float x, float y, bool force) {
    correct(&x, &y);

    Slot* clicked = find(x, y);
    if (clicked == nullptr) 
        return;
    int id = getIdentity(clicked);
    if (force || (id == int(mTurn) && mEnableMouse)) {
        if (mSelected != nullptr) 
            mSelected->resetFill();
        clicked->pick();
        mSelected = clicked;
    }
    else if (id == -1 && mSelected != nullptr) {
        MoveType type = validateMove(clicked, mSelected);
        if (type == MoveType::INVALID)
            return;

        sf::Vector2f pos = mSelected->getPosition();
        bool ender = (type == MoveType::SINGLE) || (!foundLegal(pos.x, pos.y));

        if (mEnableMouse || !ender) {
            clicked->setFillColor(mSelected->getFillColor());
            clicked->resetFill();

            mSelected->setFillColor(*mFill);
            mSelected->resetFill();

            if (ender) {
                mSelected = nullptr;
                switchTurn();
            }
            else {
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
    for (auto& s : mSlots) {
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

Checkers::MoveType Checkers::validateMove(const Slot* s1, const Slot* s2) {
    sf::Vector2f s1pos = s1->getPosition();
    sf::Vector2f s2pos = s2->getPosition();

    float distance = sqrtf(powf(s1pos.y - s2pos.y, 2) + powf(s1pos.x - s2pos.x, 2));    
    if (distance <= 4 * RADIUS)
        return MoveType::SINGLE;

    // MIDPOINT
    float midX = (s1pos.x + s2pos.x) / 2.f;
    float midY = (s1pos.y + s2pos.y) / 2.f;
    Slot* midPoint = find(midX, midY);
    if (midPoint != nullptr && getIdentity(midPoint) != -1)
        return MoveType::MULTIPLE;
    return MoveType::INVALID;
}


void Checkers::resetBoard() {
    float X = HALF, Y = HALF;
    // 9 ROW
    mSlots.emplace_back(X, Y, 9);
    for (int i = 0; i < 4; i++) {
        X -= XSTEP;
        mSlots.emplace_back(X, Y, 9);
        mSlots.emplace_back(SIZE - X, Y, 9);
    }
    Y -= YSTEP;
    int layout[8] = { 10, 11, 12, 13, 4, 3, 2, 1 };
    int buffer;
    for (int row : layout) {
        switch (row) {
        case 10: buffer = 3; break;
        case 11: buffer = 2; break;
        case 12: buffer = 2; break;
        case 13: buffer = 1; break;
        default: buffer = 0; break;
        }
        addSlotRow(&Y, row, buffer);
    }
}

void Checkers::addSlotRow(float* oY, int row, int buffer) {
    float X = HALF;
    float Y = *oY;
    int current = row;

    if (row % 2 == 0)
        X -= XSTEP / 2.f;
    else {
        if (buffer > 0)
            current = 0;
        else
            current = row;
        mSlots.emplace_back(X, Y, current);
        mSlots.emplace_back(X, SIZE - Y, current);
        X -= XSTEP;
    }
    int bound = row / 2;
    for (int j = 0; j < bound; j++) {
        if (buffer > 0) {
            if (j > buffer)
                current = row;
            else
                current = 0;
        }
        mSlots.emplace_back(X, Y, current);
        mSlots.emplace_back(X, SIZE - Y, current);
        mSlots.emplace_back(SIZE - X, Y, current);
        mSlots.emplace_back(SIZE - X, SIZE - Y, current);
        X -= XSTEP;
    }
    *oY -= YSTEP;
}

void Checkers::correct(float* x, float* y) {
    if (!mTurn) {
        *x = SIZE - *x;
        *y = SIZE - *y;
    }
}

void Checkers::config() {
    mOutline.setPosition(mCENTER);
    mOutline.setFillColor(*mFill);
    mOutline.setRadius((SIZE - 10) / 2);
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
    Slot::colors = &mColors;
    Slot::fill = mFill;
}