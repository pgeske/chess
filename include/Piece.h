#include <string>

#ifndef PIECE_H_
#define PIECE_H_

enum PieceType {Pawn, Bishop, Knight, Rook, Queen, King};

enum PieceColor {White, Black};

class Piece {
    public:
        Piece();
        Piece(PieceType p);
        Piece(PieceType p, PieceColor c);
        virtual ~Piece();
        PieceColor color;
        PieceType type;
        std::string toString();
};

#endif
