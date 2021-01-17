#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include "legals.hpp"

typedef void(*LegalsFunction)(char*, Position, PositionList*);

class Board {
private:

    static std::unordered_map<char, LegalsFunction> LEGALMAP;

    char board[8][8];
    char* boardPtr;
    bool turn;
    PositionList legals;

public:
    Board();
    void resetBoard();
    bool getTurn();
    void switchTurn();
    void print();

    // MOVE HANDLER
    void clearMoves();
    void storeMoves(const Position& pos);
    void storeMoves(const Position& pos, PositionList* moves);
    PositionList* getMoves();

};

#endif