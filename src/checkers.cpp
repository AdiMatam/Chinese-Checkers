#include "checkers.hpp"

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
bool Checkers::getTurn() const {
    return mTurn;
}
void Checkers::switchTurn() {
    mTurn = !mTurn;
}
void Checkers::draw() const {
    mWin->draw(mOutline);
    for (auto& s : mSlots) mWin->draw(s);
}
void Checkers::reset() {
    float x = HEIGHT / 2;
    float y = (HEIGHT - BOARD_DIAMETER) / 2 + STEP;
    mSlots.push_back(Slot(x, y, sf::Color::Green));
}