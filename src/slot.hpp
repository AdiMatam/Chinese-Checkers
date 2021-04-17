#ifndef SLOT_H
#define SLOT_H

#include "pch.hpp"
#include "helpers.hpp"
#include "theme.hpp"

struct Slot : public sf::CircleShape {
    static Theme* theme;
    sf::CircleShape overlay;

    Slot() = default;
    Slot(float x, float y, int row);
    ~Slot() = default;

    bool clicked(float mouseX, float mouseY) const;
    void pick();
    void resetFill();
    int getIdentity();

private:
    void determineColor(float x, float y, int row);
    void setup();
};

#endif