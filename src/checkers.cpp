#include "checkers.hpp"

Checkers::Checkers(sf::RenderWindow& win, sf::Color& fill) {
    mTurn = true;
    mWin = &win;
    mFill = &fill;
    
    mOutline.setFillColor(*mFill);
    mOutline.setOutlineColor(sf::Color::Black);
    mOutline.setOutlineThickness(2);
    mOutline.setPosition(sf::Vector2f(250, 250));
    mOutline.setRadius(100);
    mOutline.setOrigin({ mOutline.getRadius(), mOutline.getRadius() });
}
bool Checkers::getTurn() {
    return mTurn;
}
void Checkers::switchTurn() {
    mTurn = !mTurn;
}
void Checkers::draw() {
    mWin->draw(mOutline);
}
void Checkers::reset() {
    
}