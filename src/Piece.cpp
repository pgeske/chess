#include "Piece.h"


Piece::Piece() {
    return;
}

Piece::Piece(PieceType p) {
    this->type = p;
    return;
}

Piece::Piece(PieceType p, PieceColor c) {
    this->type = p;
    this->color = c;
    return;
}

Piece::~Piece() {
    return;
}

