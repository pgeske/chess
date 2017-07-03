#include "Piece.h"
#ifndef SQUARE_H_
#define SQUARE_H_

class Square {
    public:
        Square();
        virtual ~Square();
        bool attackedWhite;
        bool attackedBlack;
        Piece* piece;
};


#endif
