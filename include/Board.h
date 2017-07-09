#include "Square.h"
#include "Piece.h"
#include <vector>
#include <iostream>

#ifndef BOARD_H_
#define BOARD_H_

#define BOARD_SIZE 8

class Board {
    public:
        Board();
        virtual ~Board();
        void start();
        PieceColor turn;
        std::vector<std::vector<Square*> > board; // the game board
        int execute(int r1, int c1, int r2, int c2);
        void draw_board();
    private:
        void initialize();
        void clear();
        std::pair<int, int> translatePosition(std::string);
};

#endif
