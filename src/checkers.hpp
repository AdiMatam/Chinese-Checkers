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
    const sf::Vector2f mCENTER = sf::Vector2f(HEIGHT / 2, HEIGHT / 2);
    sf::CircleShape mOutline; // getter setter?
    sf::Transform mTrans;
    std::vector<Slot> mSlots;
    std::vector<sf::Color> mColors;
    Slot* mSelected;
    int mMoveCount;

    const float RADIAN = 3.1415 / 180;

    // STATIC
    static int sLAYOUT[17];
    static int sINDICES[17];

public:
    Checkers(sf::RenderWindow& win, sf::Color& fill);
    ~Checkers() = default;

    void rotateBoard();
    void draw() const;
    void reset();
    Slot* find(float x, float y);
    int getIdentity(const Slot* slot);
    
    int validateMove(const Slot* s1, const Slot* s2);
    void processClick(float x, float y, bool force);
    bool foundLegal(float x, float y);

    void switchTurn();
};

#endif