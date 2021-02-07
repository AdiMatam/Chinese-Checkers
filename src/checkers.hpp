#ifndef CHECKERS_H
#define CHECKERS_H

#include "pch.hpp"
#include "helpers.hpp"
#include "slot.hpp"

class Checkers {
private:
    bool mTurn;
    sf::RenderWindow* mWin;
    sf::Color* mFill;
    
    sf::CircleShape mOutline; // getter setter?
    std::vector<Slot> mSlots;

    // STATIC
    static int sLAYOUT[17];

public:
    Checkers(sf::RenderWindow& win, sf::Color& fill);
    ~Checkers() = default;

    bool getTurn() const;
    void switchTurn();
    const sf::Color& getFill() const;
    void setFill(sf::Color& fill);
    const std::vector<Slot>& getSlots() const; 

    void draw() const;
    void reset();
};

#endif