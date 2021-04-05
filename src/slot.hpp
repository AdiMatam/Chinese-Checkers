#ifndef SLOT_H
#define SLOT_H

#include "pch.hpp"
#include "helpers.hpp"

struct Slot : public sf::CircleShape {
    sf::CircleShape mOverlay;

    Slot() = default;
    Slot(float x, float y, const sf::Color& c);
    ~Slot() = default;

    bool clicked(float mouseX, float mouseY) const;
    void pick();
    void resetFill();
};

#endif