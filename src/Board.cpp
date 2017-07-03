#include "Board.h"

Board::Board() {
    return;
}

Board::~Board() {
    return;
}

bool Board::getTurn() {
    return this->turn;
}

void Board::setTurn(bool turn) {
    this->turn = turn;
}
