#include "Board.h"
#include "Square.h"
#include "Piece.h"
#include <vector>

/**
 * Returns new Board which is initialized with
 * empty Squares.
 */
Board::Board() {
    this->initialize();
    return;
}

Board::~Board() {
    this->clear();
    return;
}

/**
 * Deletes every square in Board::board
 */
void Board::clear() {
    for (int i = 0; i < this->board[i].size(); i++) {
        this->board[i].clear();
    }
    this->board.clear();
    return;
}

/**
 * Sets Board::board to a 8 x 8 board with empty Squares.
 * You should call Board::clear() first if there is an existing
 * board.
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
 * starting positions. clears and initializes first.
 */
void Board::start() {
    this->clear();
    this->initialize();
    for (int col = 0; col < 8; col++) {
        // Black Pawns
        this->board[1][col]->piece = new Piece(PieceType::Pawn, PieceColor::Black);
        // White Pawns
        this->board[6][col]->piece = new Piece(PieceType::Pawn, PieceColor::White);
        // Rooks
        if (col == 0 || col == 7) {
            this->board[0][col]->piece = new Piece(PieceType::Rook, PieceColor::Black);
            this->board[7][col]->piece = new Piece(PieceType::Rook, PieceColor::White);
        }
        // Bishops
        else if (col == 1 || col == 6) {
            this->board[0][col]->piece = new Piece(PieceType::Bishop, PieceColor::Black);
            this->board[7][col]->piece = new Piece(PieceType::Bishop, PieceColor::White);
        }
        // Knights
        else if (col == 2 || col == 5) {
            this->board[0][col]->piece = new Piece(PieceType::Knight, PieceColor::Black);
            this->board[7][col]->piece = new Piece(PieceType::Knight, PieceColor::White);
        }
        // Queens
        else if (col == 3) {
            this->board[0][col]->piece = new Piece(PieceType::Queen, PieceColor::Black);
            this->board[7][col]->piece = new Piece(PieceType::Queen, PieceColor::White);
        }
        // Kings
        else if (col == 4) {
            this->board[0][col]->piece = new Piece(PieceType::King, PieceColor::Black);
            this->board[7][col]->piece = new Piece(PieceType::King, PieceColor::White);
        }
    }
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

