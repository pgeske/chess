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

std::string Piece::toString() {
    std::string type;
    std::string color;
    if (this->type == PieceType::Pawn) {
        type = "PAWN  ";
    } else if (this->type == PieceType::Knight) {
        type = "KNIGHT";
    } else if (this->type == PieceType::Bishop) {
        type = "BISHOP";
    } else if (this->type == PieceType::King) {
        type = "KING  ";
    } else if (this->type == PieceType::Queen) {
        type = "QUEEN ";
    } else  if (this->type == PieceType::Rook) {
        type = "ROOK  ";
    } else {
    	type = "      ";
    }

    if (this->color == PieceColor::White) {
        color = "W";
    } else if (this->color == PieceColor::Black){
        color = "B";
    } else {
    	color = " ";
    }
    return color + "_" + type;
}
