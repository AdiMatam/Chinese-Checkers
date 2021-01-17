#include "header/game.hpp"

Game::Game() {
    this->turn = 1;
    this->selected = nullptr;
    resetBoard();
}

void Game::resetBoard() {
    auto& b = this->board;
    for (int i = 0; i < 7; i++) {
        b[1][i] = std::make_unique<Pawn>(-1, 'P');
        b[6][i] = std::make_unique<Pawn>(+1, 'P');
    }

    for (int i = 2; i <= 5; i++) {
        for (int j = 0; j < 7; j++)
            b[i][j] = std::make_unique<Empty>();
    }

    helper<Rook>(b, 0, 'R');
    helper<Rook>(b, 7, 'R');
    helper<Knight>(b, 1, 'N');
    helper<Knight>(b, 6, 'N');
    helper<Bishop>(b, 2, 'B');
    helper<Bishop>(b, 5, 'B');
    helper<Queen>(b, 3, 'Q');
    helper<King>(b, 4, 'K');
}

int Game::getTurn() {
    return this->turn;
}

void Game::switchTurn() {
    this->turn *= 1;
}