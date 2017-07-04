#include "Board.h"
#include "Validator.h"

Validator::Validator() {
    this->initialize();
    return;
}

Validator::~Validator() {
    this->clear();
    return;
}

/**
 * Deletes every square in both the attack maps.
 */
void Validator::clear() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        this->attackBlack[i].clear();
    }
    this->attackBlack.clear();
    for (int i = 0; i < BOARD_SIZE; i++) {
        this->attackWhite[i].clear();
    }
    this->attackWhite.clear();
    return;
}

/**
 * Sets the attack maps for each color to a 8 x 8 board with empty Squares.
 * 
 */
void Validator::initialize() {
    this->attackBlack = std::vector< std::vector<Square*> >();
    this->attackWhite = std::vector< std::vector<Square*> >();
    for (int i = 0; i < BOARD_SIZE; i++) {
        this->attackWhite.push_back(std::vector<Square*>());
        for (int j = 0; j < BOARD_SIZE; j++) {
            this->attackWhite[i].push_back(new Square());
        }
    }
    for (int i = 0; i < BOARD_SIZE; i++) {
        this->attackBlack.push_back(std::vector<Square*>());
        for (int j = 0; j < BOARD_SIZE; j++) {
            this->attackBlack[i].push_back(new Square());
        }
    }
    return;
}

/**
 * Returns true if move on board->board[r1][c1] to board->board[r2][c2]
 * is valid. Otherwise, false.
 */
bool Validator::validate(Board *board, int r1, int c1, int r2, int c2) {
    return true;
}

/**
 * Populates an attack map for a particular turn (color), given the current state of the
 * board and stores it in a 2D array called attackBlack/White corresponding to the turn.
 */
void Validator::populateAttackMap(Board *board){
	return;
}

void Validator::populateAttackMapPawn(Board *board, int r1, int c1){
	return;
}

void Validator::populateAttackMapRook(Board *board, int r1, int c1){
	return;
}

void Validator::populateAttackMapBishop(Board *board, int r1, int c1){
	return;
}

void Validator::populateAttackMapQueen(Board *board, int r1, int c1){
	return;
}

void Validator::populateAttackMapKing(Board *board, int r1, int c1){
	return;
}

/**
 * Returns a vector of all Square*s which the piece in board->board[r1][c1]
 * can travel to.
 */
std::vector<Square*> Validator::allowed(Board *board, int r1, int c1) {
    std::vector<Square*> allowedSquares;
    Piece *piece = board->board[r1][c1]->piece;
    // No piece
    if (!piece) {
        return allowedSquares;
    }
    // Pawn
    else if (piece->type == PieceType::Pawn) {
    }
    // Rook
    else if (piece->type == PieceType::Rook) {
    }
    // Bishop
    else if (piece->type == PieceType::Bishop) {
    }
    // Queen
    else if (piece->type == PieceType::Queen) {
    }
    // King -- Trickier
    return allowedSquares;
}

/**
 * Like Validator::allowed, but assumes Pawn is at that coordinate.
 * TODO: before pushing it to possible, AND it with the attackWhite/Black
 * map. Attack map gives 0 if an attack is possible and 1 if not.
 */
std::vector<Square*> Validator::allowedPawn(Board *board, int r1, int c1) {
    Piece *piece = board->board[r1][c1]->piece;
    std::vector<Square*> possible;
    if (piece->color == PieceColor::White) {
        if (r1 < BOARD_SIZE) {
            if (board->board[r1 + 1][c1]->piece->color != PieceColor::White) {
                possible.push_back(board->board[r1 + 1][c1]);
            }
        } else if (c1 > 0) {
            if (board->board[r1 + 1][c1 - 1]->piece->color == PieceColor::Black) {
                possible.push_back(board->board[r1 + 1][c1 - 1]);
            }
        } else if (c1 < BOARD_SIZE) {
            if (board->board[r1 + 1][c1 + 1]->piece->color == PieceColor::Black) {
                possible.push_back(board->board[r1 + 1][c1 + 1]);
            }
        } 
    } else if (piece->color == PieceColor::Black) {
        if (r1 > 0) {
            if (board->board[r1 - 1][c1]->piece->color != PieceColor::Black) {
                possible.push_back(board->board[r1 - 1][c1]);
            }
        } else if (c1 > 0) {
            if (board->board[r1 - 1][c1 - 1]->piece->color == PieceColor::White) {
                possible.push_back(board->board[r1 - 1][c1 - 1]);
            }
        } else if (c1 < BOARD_SIZE) {
            if (board->board[r1 - 1][c1 + 1]->piece->color == PieceColor::White) {
                possible.push_back(board->board[r1 - 1][c1 + 1]);
            }
        } 
    }
    return possible;
}

/**
 * Like Validator::allowed, but assumes Rook is at that coordinate.
 */
std::vector<Square*> Validator::allowedRook(Board *board, int r1, int c1) {
    std::vector<Square*> possible;
    PieceColor color = board->board[r1][c1]->piece->color;
    PieceColor opposite = (color == PieceColor::White) ? PieceColor::Black : PieceColor::White;
    // Left
    for (int col = c1 - 1; col >= 0; col--) {
        if (board->board[r1][col]->piece->color == color) break;
        possible.push_back(board->board[r1][col]);
        if (board->board[r1][col]->piece->color == opposite) break;
    }
    // Right
    for (int col = c1 + 1; col < BOARD_SIZE; col++) {
        if (board->board[r1][col]->piece->color == color) break;
        possible.push_back(board->board[r1][col]);
        if (board->board[r1][col]->piece->color == opposite) break;
    }
    // Up
    for (int row = row + 1; row < BOARD_SIZE; row++) {
        if (board->board[row][c1]->piece->color == color) break;
        possible.push_back(board->board[row][c1]);
        if (board->board[row][c1]->piece->color == opposite) break;
    }
    // Down
    for (int row = row - 1; row >= 0; row--) {
        if (board->board[row][c1]->piece->color == color) break;
        possible.push_back(board->board[row][c1]);
        if (board->board[row][c1]->piece->color == opposite) break;
    }
    return possible;
}

/**
 * Like Validator::allowed, but assumes Knight is at that coordinate.
 */
std::vector<Square*> Validator::allowedKnight(Board *board, int r1, int c1) {
    std::vector<Square*> possible;
    PieceColor color = board->board[r1][c1]->piece->color;
    PieceColor opposite = (color == PieceColor::White) ? PieceColor::Black : PieceColor::White;
    std::vector<std::pair<int, int>> coordinates;
    coordinates.push_back(std::make_pair(r1 + 2, c1 - 1));
    coordinates.push_back(std::make_pair(r1 + 2, c1 + 1));
    coordinates.push_back(std::make_pair(r1 + 1, c1 + 2));
    coordinates.push_back(std::make_pair(r1 - 1, c1 + 2));
    coordinates.push_back(std::make_pair(r1 - 2, c1 + 1));
    coordinates.push_back(std::make_pair(r1 - 2, c1 - 1));
    coordinates.push_back(std::make_pair(r1 - 1, c1 - 2));
    coordinates.push_back(std::make_pair(r1 + 1, c1 - 2));
    for (int i = 0; i < coordinates.size(); i++) {
        int row = coordinates[i].first;
        int col = coordinates[i].second;
        if (board->board[row][col]->color == color) continue;
        if (row < 0 || row > BOARD_SIZE || col < 0 || col > BOARD_SIZE) continue;
        possible.push_back(board->board[row][col]);
    }
    return possible;
}

/**
 * Like Validator::allowed, but assumes Bishop is at that coordinate.
 */
std::vector<Square*> Validator::allowedBishop(Board *board, int r1, int c1) {
}

/**
 * Like Validator::allowed, but assumes Queen is at that coordinate.
 */
std::vector<Square*> Validator::allowedQueen(Board *board, int r1, int c1) {
}


/**
 * Like Validator::allowed, but assumes King is at that coordinate.
 */
std::vector<Square*> Validator::allowedKing(Board *board, int r1, int c1) {
}

