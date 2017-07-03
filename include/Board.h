#include "Square.h"
#include "Piece.h"
#include <vector>

#ifndef BOARD_H_
#define BOARD_H_

class Board {
    public:
        Board();
        virtual ~Board();
        void initialize();
        void start();
        void clear();
        PieceColor turn;
        std::vector<std::vector<Square*>> board; // the game board
        int execute(int r1, int c1, int r2, int c2);
    private:
        bool isValid(int r1, int c1, int r2, int c2);
};

#endif
