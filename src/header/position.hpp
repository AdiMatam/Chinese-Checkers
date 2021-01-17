#ifndef POSITION_H
#define POSITION_H

#include <vector>

struct Position {
    int row, col;
    Position() = default;
    Position(int row, int col);
    Position(const Position& other);
    inline bool operator==(const Position& other) const;
};

typedef std::vector<Position> PositionList;

#endif


    // Position(Position&& other);
    // Position& operator=(Position&& other);
    // void print() const;