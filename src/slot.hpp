#ifndef SLOT_H
#define SLOT_H

#include "pch.hpp"
#include "piece.hpp"

struct Slot {
    int x, y;
    Piece* piece;
    std::vector<Slot*> neighbors;

    Slot() = default;
    Slot(int x, int y);
    Slot(Slot&& other);
    ~Slot() = default;
    // ADD OTHER CONSTRUCTORS AS NEEDED
    
    void addNeighbor(const Slot& slot);
    bool clicked(int mouseX, int mouseY);
    void print();
};

#endif