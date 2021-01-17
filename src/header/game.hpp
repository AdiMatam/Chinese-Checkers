#ifndef GAME_H
#define GAME_H

#include <memory>
#include "piece.hpp"

typedef std::unique_ptr<Piece> PiecePtr;

template<class T>
void helper(PiecePtr(&board)[8][8], int file, char t) {
    board[0][file] = std::make_unique<T>(-1, t);
    board[7][file] = std::make_unique<T>(+1, t);
}

class Game {
private:
    int turn;
    Piece* selected;
    // PositionList legals;
    PiecePtr board[8][8];

public:
    Game();
    void resetBoard();
    int getTurn();
    void switchTurn();

};

#endif