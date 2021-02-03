#ifndef CHECKERS_H
#define CHECKERS_H

#include "pch.hpp"
// #include "slot.hpp"

class Checkers {
private:
    bool mTurn;
    sf::RenderWindow* mWin;
    sf::Color* mFill;
    sf::CircleShape mOutline;

    const int LAYOUT[17] = {
        1, 2, 3, 4, 13, 12, 11, 10, 9, 
        10, 11, 12, 13, 4, 3, 2, 1
    };

public:
    Checkers(sf::RenderWindow& win, sf::Color& fill);
    ~Checkers() = default;

    bool getTurn();
    void switchTurn();
    void draw();
    void reset();
};

#endif