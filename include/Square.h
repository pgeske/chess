#include "Piece.h"

class Square {
    public:
        Square();
        virtual ~Square();
        bool attackedWhite;
        bool attackedBlack;
        Piece* piece;
};
