#include "checkers.hpp"

int Checkers::sLAYOUT[17] = {
    1, 2, 3, 4, 13, 12, 11, 10, 9, 
    10, 11, 12, 13, 4, 3, 2, 1
};


Checkers::Checkers(sf::RenderWindow& win, sf::Color& fill) {
    mTurn = true;
    mWin = &win;
    mFill = &fill;
    mRotation = 0;

    mOutline.setPosition(mCENTER);
    mOutline.setFillColor(*mFill);
    mOutline.setRadius(BOARD_DIAMETER / 2);
    mOutline.setOutlineColor(sf::Color::Black);
    mOutline.setOutlineThickness(THICK);
    mOutline.setPointCount(mOutline.getPointCount() * 2);
    mOutline.setOrigin(mOutline.getRadius(), mOutline.getRadius());

    mColors.reserve(6);
    mColors[0] = sf::Color::White;
    mColors[1] = sf::Color::Red;
    mColors[2] = sf::Color::Blue;
    mColors[3] = sf::Color::Yellow;
    mColors[4] = sf::Color::Green;
    mColors[5] = sf::Color(65, 65, 65);
    
    reset();
    if (mSlots.size() != 121) logf("Actual Slot Count: %d", mSlots.size());
}
void Checkers::draw() const {
    mWin->draw(mOutline);
    for (auto& s : mSlots) mWin->draw(s, mTrans);
}

void Checkers::rotateBoard() {
    mRotation++;
    if (mRotation == 181) mRotation = 0;
    else mTrans.rotate(1, mCENTER);
}

void Checkers::reset() {
    float x;
    float y = 2 * GAP + RADIUS;
    const sf::Color* colorStepper = &mColors[0];
    const sf::Color* current;
    int rowCount;

    int guide[] = {0,0,0,0,-1,2,3,3,4,5,-2,4,3,3,2,-2,0,0,0,0};
    int* guidePtr = &guide[0];

    for (int i = 0; i < 17; i++) {
        current = mFill;
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
                mSlots.push_back(Slot(x, y, *current));
            else
                mSlots.push_back(Slot(x, y, *colorStepper));
            x -= STEP;
        }

        for (int j = 0; j < rowCount / 2; j++) {
            if (*guidePtr <= j) current = colorStepper;
            mSlots.push_back(Slot(x, y, *current));
            if (rowCount > 4)
                mSlots.push_back(Slot(HEIGHT - x, y, *(current+1)));
            else
                mSlots.push_back(Slot(HEIGHT - x, y, *current));
            x -= STEP;
        }
        y += STEP;
        guidePtr++;
    }
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
const std::vector<Slot>& Checkers::getSlots() const {
    return mSlots;
}
int Checkers::getRotation() const {
    return mRotation;
}