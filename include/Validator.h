#include "Board.h"
#include <vector>

#ifndef _VALIDATOR_H_
#define _VALIDATOR_H_

class Validator {
    public:
        Validator();
        ~Validator();
        static bool validate(Board *board, int r1, int c1, int r2, int c2);
        std::vector<Square*> allowed(Board *board, int r1, int c1);
    private:
        void initialize();
        void clear();
        void populateAttackMap(Board *board);
        void populateAttackMapPawn(Board*, int, int);
        void populateAttackMapRook(Board*, int, int);
        void populateAttackMapBishop(Board*, int, int);
        void populateAttackMapQueen(Board*, int, int);
        void populateAttackMapKing(Board*, int, int);
        std::vector<Square*> allowedPawn(Board *board, int r1, int c1);
        std::vector<Square*> allowedRook(Board *board, int r1, int c1);
        std::vector<Square*> allowedBishop(Board *board, int r1, int c1);
        std::vector<Square*> allowedKnight(Board *board, int r1, int c1);
        std::vector<Square*> allowedQueen(Board *board, int r1, int c1);
        std::vector<Square*> allowedKing(Board *board, int r1, int c1);
        std::vector<std::vector<bool> > attackWhite; // possible attack positions of white pieces
        std::vector<std::vector<bool> > attackBlack; // possible attack positions of black pieces
};

#endif
