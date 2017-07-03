#include "Square.h"

Square::Square() {
    this->attackedWhite = false;
    this->attackedBlack = false;
    this->piece = 0;
    return;
}

Square::~Square() {
    delete this->piece;
    return;
}

/**
 * Returns the Piece* on this Square and removes it 
 * from Square::piece.
 */
Piece* Square::liftPiece() {
    Piece* piece = this->piece;
    this->piece = 0;
    return piece;
}

/**
 * Deletes Square::piece from the game and memory. Should
 * be called when the Piece is conquered.
 */
void Square::removePiece() {
    delete this->piece;
}
