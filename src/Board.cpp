#include "Board.h"
#include "Square.h"
#include <vector>

Board::Board() {
    return;
}

Board::~Board() {
    return;
}

/**
 * Initializes board with 8 x 8 Squares
 */
void Board::initialize() {
    this->board = std::vector<std::vector<Square*>>();
    for (int i = 0; i < 8; i++) {
        this->board.push_back(std::vector<Square*>());
        for (int j = 0; j < 8; j++) {
            this->board[i].push_back(new Square());
        }
    }
    return;
}

/**
 * Populates Squares in board with pieces in their 
 * starting positions.
 */
void Board::start() {
    return;
}

/**
 * Clears all pieces on the board.
 */
void Board::clear() {
    return;
}


/**
 * Attempts to execute move from board[r1][c1] to board[r2][c2].
 * If this move is valid and succesful, returns 0. Otherwise, 
 * returns 1.
 */
int Board::execute(int r1, int c1, int r2, int c2) {
    return 0;
}

/**
 * True if the move from board[r1][c1] to board[r2][c2] is valid.
 * Otherwise, false.
 */
bool Board::isValid(int r1, int c1, int r2, int c2) {
    return false;
}

