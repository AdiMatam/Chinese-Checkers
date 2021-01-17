#include "header/legals.hpp"
#include "header/board.hpp"


Board::Board() {
    resetBoard();
    this->turn = true;
    this->boardPtr = &this->board[0][0];
    if (LEGALMAP.size() == 0) {
        LEGALMAP['P'] = &pawnMoves;
        LEGALMAP['B'] = &bishopMoves;
        LEGALMAP['N'] = &knightMoves;
        LEGALMAP['Q'] = &queenMoves;
        LEGALMAP['K'] = &kingMoves;
        LEGALMAP['R'] = &rookMoves;
    }
}

void Board::resetBoard() {
    for (int i = 0; i < 8; i++) {
        std::string row;
        switch (i) {
        case 0:
            row = "rnbqkbnr";
            break;
        case 1:
            row = "pppppppp";
            break;
        case 6:
            row = "PPPPPPPP";
            break;
        case 7:
            row = "RNBQKBNR";
            break;
        default:
            row = "--------";
            break;
        }
        for (int j = 0; j < 8; j++)
            this->board[i][j] = row[j];
    }
}
bool Board::getTurn() {
    return this->turn;
}
void Board::switchTurn() {
    this->turn = !this->turn;
}
void Board::print() {
    for (int i = 0; i < 8; i++) {
        std::cout << "| ";
        for (int j = 0; j < 8; j++)
            std::cout << board[i][j] << " | ";
        std::cout << std::endl;
    }
}
void Board::clearMoves() {
    this->legals.clear();
}

void Board::storeMoves(const Position& pos) {
    storeMoves(pos, &this->legals);
}
void Board::storeMoves(const Position& pos, PositionList* moves) {
    char piece = this->board[pos.row][pos.col];
    if (!evalColor(piece))
        piece -= 32;
    LEGALMAP[piece](this->boardPtr, pos, moves);   
}

PositionList* Board::getMoves() {
    return &this->legals;
}