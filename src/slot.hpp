#ifndef SLOT_H
#define SLOT_H

#include "pch.hpp"
#include "helpers.hpp"
// #include "piece.hpp"

struct Slot : public sf::CircleShape {
    
    std::vector<Slot*> mNeighbors;

    Slot() = default;
    Slot(float x, float y, const sf::Color& c);
    ~Slot() = default;
    // ADD OTHER CONSTRUCTORS AS NEEDED
    
    // void config();
    void addNeighbor(Slot& slot);
    bool clicked(float mouseX, float mouseY);
    void print();
};

#endif