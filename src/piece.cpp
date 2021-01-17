#include "header/piece.hpp"

int Piece::getColor() const {
    return this->color;
}

Rook::Rook(int color) {
    this->color = color;
}

void Rook::getMoves(PositionList& list) {
    
}

