#include "header/legals.hpp"

inline bool evalColor(char piece) {
    return piece >= 65 && piece <= 90; // true for uppercase (white pieces)
}
inline char pieceAt(char* board, const Position& pos) {
    return *(board + (pos.row * 8 + pos.col));
}

void rookMoves(char* board, Position current, PositionList* list) {
    char out;
    bool color = evalColor(pieceAt(board, current));
    while (current.col < 7) {
        current.col++;
        out = pieceAt(board, current);
        if (out == '-' || evalColor(out) != color)
            list->push_back(current);
            if (out != '-') break;
        else break;
    }
}

void pawnMoves(char* board, Position current, PositionList* list) {

}

void bishopMoves(char* board, Position current, PositionList* list) {

}
void knightMoves(char* board, Position current, PositionList* list) {

}
void queenMoves(char* board, Position current, PositionList* list) {

}
void kingMoves(char* board, Position current, PositionList* list) {

}