#include "checkers.hpp"

int Checkers::sLAYOUT[17] = {
    1, 2, 3, 4, 13, 12, 11, 10, 9, 
    10, 11, 12, 13, 4, 3, 2, 1
};

Checkers::Checkers(sf::RenderWindow& win, sf::Color& fill) {
    mTurn = true;
    mWin = &win;
    mFill = &fill;

    mOutline.setPosition(sf::Vector2f(HEIGHT / 2, HEIGHT / 2));
    mOutline.setFillColor(*mFill);
    mOutline.setRadius(BOARD_DIAMETER / 2);
    mOutline.setOutlineColor(sf::Color::Black);
    mOutline.setOutlineThickness(THICK);
    mOutline.setPointCount(mOutline.getPointCount() * 2);
    mOutline.setOrigin(mOutline.getRadius(), mOutline.getRadius());

    reset();
}
void Checkers::draw() const {
    mWin->draw(mOutline);
    for (auto& s : mSlots) mWin->draw(s);
}
void Checkers::reset() {
    float x;
    float y = 2 * GAP + RADIUS;
    const auto& c = sf::Color::Blue;

    for (int i = 0; i < 17; i++) {
        x = HEIGHT / 2;
        const int& count = sLAYOUT[i];
        if (count % 2 == 1) {
            mSlots.push_back(Slot(x, y, c));
            x -= STEP;
        }
        else
            x -= (RADIUS + GAP / 2.f);
        for (int j = 0; j < count / 2; j++) {
            mSlots.push_back(Slot(x, y, c));
            mSlots.push_back(Slot(HEIGHT - x, y, c));
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
