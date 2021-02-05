#include "checkers.hpp"

Checkers::Checkers(sf::RenderWindow& win, sf::Color& fill) {
    mTurn = true;
    mWin = &win;
    mFill = &fill;
    
    mOutline.setFillColor(*mFill);
    mOutline.setOutlineColor(sf::Color::Black);
    mOutline.setOutlineThickness(THICK);
    mOutline.setPosition(sf::Vector2f(HEIGHT / 2, HEIGHT / 2));
    mOutline.setRadius(RADIUS);
    mOutline.setPointCount(mOutline.getPointCount() * 2);
    mOutline.setOrigin({ mOutline.getRadius(), mOutline.getRadius() });
}
bool Checkers::getTurn() const {
    return mTurn;
}
void Checkers::switchTurn() {
    mTurn = !mTurn;
}
void Checkers::draw() const {
    mWin->draw(mOutline);
}
void Checkers::reset() {
    
}