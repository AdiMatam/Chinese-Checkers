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

    mTest.setFillColor(*mFill);
    mTest.setOutlineColor(sf::Color::Black);
    mTest.setOutlineThickness(THICK);
    mTest.setPosition(sf::Vector2f(HEIGHT / 2, HEIGHT / 2 - STEP));
    mTest.setRadius(RADIUS);
    mTest.setPointCount(mTest.getPointCount() * 2);
    mTest.setOrigin({ mTest.getRadius(), mTest.getRadius() });

    mOutline2.setFillColor(*mFill);
    mOutline2.setOutlineColor(sf::Color::Black);
    mOutline2.setOutlineThickness(THICK);
    mOutline2.setPosition(sf::Vector2f(HEIGHT / 2, HEIGHT / 2));
    mOutline2.setRadius(BOARD_DIAMETER / 2);
    mOutline2.setPointCount(mOutline2.getPointCount() * 2);
    mOutline2.setOrigin({ mOutline2.getRadius(), mOutline2.getRadius() });
}
bool Checkers::getTurn() {
    return mTurn;
}
void Checkers::switchTurn() {
    mTurn = !mTurn;
}
void Checkers::draw() {
    mWin->draw(mOutline2);
    mWin->draw(mOutline);
    mWin->draw(mTest);
}
void Checkers::reset() {
    
}