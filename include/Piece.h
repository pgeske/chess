#include <string>

enum PieceType {Pawn, Bishop, Knight, Rook, Queen, King};

class Piece {
    public:
        Piece();
        Piece(PieceType p);
        virtual ~Piece();
        bool color; // true if white, false if black
        PieceType type;
};

