#include "Piece.h"

class Square {
    public:
        Square();
        virtual ~Square();
        bool getAttackedWhite();
        bool getAttackedBlack();
        void setAttackedWhite(bool value);
        void setAttackedBlack(bool value);
        Piece* getPiece();
        void setPiece(Piece* piece);
    private:
        bool attackedWhite;
        bool attackedBlack;
        Piece* piece;
};
