#ifndef CHECKERS_H
#define CHECKERS_H

#include "Pch.hpp"
#include "Helpers.hpp"
#include "Slot.hpp"

class Checkers {
private:
    bool mTurn;
    sf::RenderWindow* mWin;
    sf::Color* mFill;
    const sf::Vector2f mCENTER = { HEIGHT / 2, HEIGHT / 2 };
    sf::CircleShape mOutline; // getter setter?
    sf::Transform mTrans;
    int mRotation;
    std::vector<Slot> mSlots;
    std::vector<sf::Color> mColors;

    // STATIC
    static int sLAYOUT[17];

    void addSlot(int x, int y, int rowCount, sf::Color* oneToFour, sf::Color* rest);

public:
    Checkers(sf::RenderWindow& win, sf::Color& fill);
    ~Checkers() = default;

    bool getTurn() const;
    void switchTurn();
    const sf::Color& getFill() const;
    void setFill(sf::Color& fill);
    std::vector<Slot>& getSlots(); 
    int getRotation() const;

    void rotateBoard();
    void draw() const;
    void reset();
};

#endif