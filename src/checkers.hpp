#ifndef CHECKERS_H
#define CHECKERS_H

#include "pch.hpp"

class Checkers {
private:
    bool turn;
    sf::RenderWindow* win;

    const int layout[17] = {
        1, 2, 3, 4, 13, 12, 11, 10, 9, 
        10, 11, 12, 13, 4, 3, 2, 1
    };

public:
    Checkers(sf::RenderWindow* win);
    ~Checkers() = default;

    bool getTurn();
    void draw();
    void reset();
};

#endif