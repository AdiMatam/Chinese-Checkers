#ifndef SLOT_H
#define SLOT_H

#include "pch.hpp"
#include "helpers.hpp"
// #include "piece.hpp"

struct Slot : public sf::CircleShape {
    
    std::vector<Slot*> mNeighbors;

    Slot() = default;
    Slot(int x, int y, const sf::Color& c=sf::Color::White);
    ~Slot() = default;
    // ADD OTHER CONSTRUCTORS AS NEEDED
    
    void addNeighbor(Slot& slot);
    bool clicked(int mouseX, int mouseY);
    void print();
};

#endif