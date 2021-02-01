#ifndef PIECE_H
#define PIECE_H

#include "pch.hpp"

struct Piece {
    sf::Color* color;
    int master;

    Piece() = default;
    Piece(const sf::Color& c, int master);
    Piece(Piece&& other);
    ~Piece() = default;
};

#endif