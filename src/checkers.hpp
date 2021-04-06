#ifndef CHECKERS_H
#define CHECKERS_H

#include "pch.hpp"
#include "helpers.hpp"
#include "slot.hpp"

class Checkers {
private:
    sf::RenderWindow* mWin;
    sf::Color* mFill;
    sf::CircleShape mOutline;
    sf::Transform mTrans;
    std::vector<Slot> mSlots;
    std::vector<sf::Color> mColors;
    
    bool mTurn;
    Slot* mSelected;
    bool mEnableMouse;

    const sf::Vector2f mCENTER = sf::Vector2f(HEIGHT / 2, HEIGHT / 2);
    const float RADIAN = 3.1415f / 180.f;

    static int sINDICES[18];

    enum MoveType {
        INVALID, SINGLE, MULTIPLE
    };
    
public:
    Checkers(sf::RenderWindow& win, sf::Color& fill);
    ~Checkers() = default;

    void rotateBoard();
    void draw() const;
    void resetBoard();
    
    Slot* find(float x, float y);
    int getIdentity(const Slot* slot);
    MoveType validateMove(const Slot* s1, const Slot* s2);
    void processClick(float x, float y, bool force);
    bool foundLegal(float x, float y);

    void switchTurn();
    bool movedAtAll();

private:
    void config();
};

#endif