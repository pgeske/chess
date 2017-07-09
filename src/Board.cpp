#include "Board.h"
#include "Validator.h"

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
    for (int i = 0; i < BOARD_SIZE; i++) {
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
    this->board = std::vector< std::vector<Square*> >();
    for (int i = 0; i < BOARD_SIZE; i++) {
        this->board.push_back(std::vector<Square*>());
        for (int j = 0; j < BOARD_SIZE; j++) {
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
    for (int col = 0; col < BOARD_SIZE; col++) {
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
        //None
        this->board[2][col]->piece = new Piece(PieceType::None, PieceColor::Na);
        this->board[3][col]->piece = new Piece(PieceType::None, PieceColor::Na);
        this->board[4][col]->piece = new Piece(PieceType::None, PieceColor::Na);
        this->board[5][col]->piece = new Piece(PieceType::None, PieceColor::Na);
    }
    return;
}



/**
 * Attempts to execute move from board[r1][c1] to board[r2][c2].
 * If this move is valid and succesful, returns 0. Otherwise, 
 * returns 1.
 */
int Board::execute(int r1, int c1, int r2, int c2) {
    // Check to see if move is valid
    if (!Validator::validate(this, r1, c1, r2, c2)) return 1;

    // Move the piece and do any capturing if necessary
    Square *source = this->board[r1][c1];
    Square *dest = this->board[r2][c2];
    dest->removePiece();
    dest->piece = source->liftPiece();
    return 0;
}

/**
 * Given a position of the form e.g "e2", translates this into 
 * a pair of coordinates.
 */
std::pair<int, int> Board::translatePosition(std::string position) {
    int row, col;
    return std::make_pair(row, col);
}

/**
 * Draws the board to cout. For testing purposes.
 */
void Board::draw_board(){
	for (int row=0; row<BOARD_SIZE; row++){
		std::cout<<"  ---------- "<<"  ----------  "<<"  ---------- "<<"  ---------- "<<"  ---------- "<<"  ---------- "<<"  ---------- "<<"  ---------- "<<std::endl;
		std::cout<<"|  "<<this->board[row][0]->piece->toString()<<"  |  ";
		std::cout<<this->board[row][1]->piece->toString() <<"  |  ";
		std::cout<<this->board[row][2]->piece->toString() <<"  |  ";
		std::cout<<this->board[row][3]->piece->toString() <<"  |  ";
		std::cout<<this->board[row][4]->piece->toString() <<"  |  ";
		std::cout<<this->board[row][5]->piece->toString() <<"  |  ";
		std::cout<<this->board[row][6]->piece->toString() <<"  |  ";
		std::cout<<this->board[row][7]->piece->toString() <<"  |  ";
		std::cout<<std::endl;
	}
	std::cout<<"  ---------- "<<"  ----------  "<<"  ---------- "<<"  ---------- "<<"  ---------- "<<"  ---------- "<<"  ---------- "<<"  ---------- "<<std::endl;
	return;
	
}
