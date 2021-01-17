#include "header/position.hpp"
// #include <cstdio>

Position::Position(int row, int col) : row(row), col(col) {}
Position::Position(const Position& other) {
    this->row = other.row;
    this->col = other.col;
}
inline bool Position::operator==(const Position& other) const {
    return this->row == other.row && this->col == other.col;
}



// Position::Position(Position&& other) {
//     this->row = other.row;
//     this->col = other.col;
// }
// Position& Position::operator=(Position&& other) {
//     this->row = other.row;
//     this->col = other.col;
//     return *this;
// }
// void Position::print() const {
//     printf("%d, %d", this->row, this->col);
// }