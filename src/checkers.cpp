#include "checkers.hpp"

int Checkers::sLAYOUT[17] = {
    1, 2, 3, 4, 13, 12, 11, 10, 9, 
    10, 11, 12, 13, 4, 3, 2, 1
};

Checkers::Checkers(sf::RenderWindow& win, sf::Color& fill) {
    mTurn = true;
    mWin = &win;
    mFill = &fill;

    mOutline.setPosition(mCENTER);
    mOutline.setFillColor(*mFill);
    mOutline.setRadius(BOARD_DIAMETER / 2);
    mOutline.setOutlineColor(sf::Color::Black);
    mOutline.setOutlineThickness(THICK);
    mOutline.setPointCount(mOutline.getPointCount() * 2);
    mOutline.setOrigin(mOutline.getRadius(), mOutline.getRadius());

    // mTrans.rotate(90, mCENTER);

    reset();
    if (mSlots.size() != 121) logf("Actual Slot Count: %d", mSlots.size());
}
void Checkers::draw() const {
    mWin->draw(mOutline);
    for (auto& s : mSlots) mWin->draw(s, mTrans);
}
void Checkers::reset() {
    float x;
    float y = 2 * GAP + RADIUS;
    const auto* c = &sf::Color::Blue;
    int count;

    for (int i = 0; i < 17; i++) {
        if (i > 7) c = &sf::Color::Red;

        x = HEIGHT / 2;
        count = sLAYOUT[i];
        if (count % 2 == 1) {
            mSlots.push_back(Slot(x, y, *c));
            x -= STEP;
        }
        else x -= (RADIUS + GAP / 2.f);
        for (int j = 0; j < count / 2; j++) {
            mSlots.push_back(Slot(x, y, *c));
            mSlots.push_back(Slot(HEIGHT - x, y, *c));
            x -= STEP;
        }
        y += STEP;
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

void Checkers::rotate() {
    mTrans.rotate(1, mCENTER);
    // int x = 1;
    // for (int x = 0; x < 180; x++) {
    //     mTrans.rotate(1, mCENTER);
    //     draw();
    //     Sleep(50);
    // }
}