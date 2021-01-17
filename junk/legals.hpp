#ifndef LEGALS_H
#define LEGALS_H

#include "position.hpp"

inline bool evalColor(char piece);
inline char pieceAt(char* board, const Position& pos);

void pawnMoves(  char* board, Position current, PositionList* list);
void bishopMoves(char* board, Position current, PositionList* list);
void knightMoves(char* board, Position current, PositionList* list);
void queenMoves( char* board, Position current, PositionList* list);
void kingMoves(  char* board, Position current, PositionList* list);
void rookMoves(  char* board, Position current, PositionList* list);

#endif