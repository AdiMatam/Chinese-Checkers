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
    
    const sf::Vector2f mCENTER = { HEIGHT / 2, HEIGHT / 2 };
    sf::CircleShape mOutline; // getter setter?
    sf::Transform mTrans;
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

    void rotate();
    void draw() const;
    void reset();
};

#endif