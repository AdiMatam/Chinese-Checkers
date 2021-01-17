#ifndef PIECE_H
#define PIECE_H

#include "position.hpp"

class Piece {
protected:
    int color;
    char type;
    // texture*
public:
    int getColor() const;
    char getType() const;
    void setColor(int color);
    void setType(char type);
    // getImage() const;
    // setImage();
    virtual void getMoves(PositionList& list) = 0;
};

class Rook : public Piece {
public:
    Rook();
    void getMoves(PositionList& list);
};

class Bishop : public Piece {
public:
    Bishop();
    void getMoves(PositionList& list);
};

class Knight : public Piece {
public:
    Knight();
    void getMoves(PositionList& list);
};

class Queen : public Piece {
public:
    Queen();
    void getMoves(PositionList& list);
};


class King : public Piece {
public:
    King();
    void getMoves(PositionList& list);
};

class Pawn : public Piece {
public:
    Pawn();
    void getMoves(PositionList& list);
};

class Empty : public Piece {
public:
    Empty();
    void getMoves(PositionList& list);
};

#endif