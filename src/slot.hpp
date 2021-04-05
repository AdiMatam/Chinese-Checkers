#ifndef SLOT_H
#define SLOT_H

#include "pch.hpp"
#include "helpers.hpp"

struct Slot : public sf::CircleShape {
    
    // std::vector<Slot*> mNeighbors;
    sf::CircleShape mOverlay;

    Slot() = default;
    Slot(float x, float y, const sf::Color& c);
    ~Slot() = default;
    // ADD OTHER CONSTRUCTORS AS NEEDED
    
    // void config();
    // void addNeighbor(Slot& slot);
    bool clicked(float mouseX, float mouseY) const;
    void print() const;
    void pick();
    void resetFill();
};

#endif