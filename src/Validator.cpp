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
    this->attackBlack = std::vector< std::vector<bool> >();
    this->attackWhite = std::vector< std::vector<bool> >();
    for (int i = 0; i < BOARD_SIZE; i++) {
        this->attackWhite.push_back(std::vector<bool>());
        for (int j = 0; j < BOARD_SIZE; j++) {
            this->attackWhite[i].push_back(1);
        }
    }
    for (int i = 0; i < BOARD_SIZE; i++) {
        this->attackBlack.push_back(std::vector<bool>());
        for (int j = 0; j < BOARD_SIZE; j++) {
            this->attackBlack[i].push_back(1);
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


bool Validator::boundsCheck(int r1, int c1){
	if(r1>=0 && r1<BOARD_SIZE && c1>=0 && c1<BOARD_SIZE){
		return 1;
	} else {
		return 0;
	}
}


/**
 * Generates the requested possible moves of the Pawn, if the 
 * path is reachable. Returns a vector of coordinates.
 */

std::vector<std::pair<int, int> > Validator::generatePawn(const Board* board, int r1, int c1, bool isBlack){
    std::vector<std::pair<int, int> > coordinates;
	PieceColor same = (isBlack) ? PieceColor::Black : PieceColor::White;
    
    if(this->boundsCheck(r1 + 1,c1 + 1)){
		if(board->board[r1 + 1][c1 + 1]->piece->color != same){
    		coordinates.push_back(std::make_pair(r1 + 1, c1 + 1));
		}
	}
    if(this->boundsCheck(r1 + 1,c1 - 1)){
		if(board->board[r1 + 1][c1 - 1]->piece->color != same){
    		coordinates.push_back(std::make_pair(r1 + 1, c1 - 1));
		}
	}
    if(this->boundsCheck(r1 + 1,c1)){
		if(board->board[r1 + 2][c1]->piece->color != same){
    		coordinates.push_back(std::make_pair(r1 + 1, c1));
		}
	}
	return coordinates;
}

/**
 * Generates the requested possible moves of the Knight, if the 
 * path is reachable. Returns a vector of coordinates.
 */

std::vector<std::pair<int, int> > Validator::generateKnight(const Board* board, int r1, int c1, bool isBlack){
    std::vector<std::pair<int, int> > coordinates;
	PieceColor same = (isBlack) ? PieceColor::Black : PieceColor::White;

    if(boundsCheck(r1 + 2, c1 - 1)){
		if(board->board[r1 + 2][c1 - 1]->piece->color != same){
    		coordinates.push_back(std::make_pair(r1 + 2, c1 - 1));
		}
	}
	if(boundsCheck(r1 + 2,c1 + 1)){
		if(board->board[r1 + 2][c1 + 1]->piece->color != same){
    		coordinates.push_back(std::make_pair(r1 + 2, c1 + 1));
		}
	}
	if(boundsCheck(r1 + 1,c1 + 2)){
		if(board->board[r1 + 1][c1 + 2]->piece->color != same){
    		coordinates.push_back(std::make_pair(r1 + 1, c1 + 2));
		}
	}
	if(boundsCheck(r1 - 1,c1 + 2)){
		if(board->board[r1 - 1][c1 + 2]->piece->color != same){
    		coordinates.push_back(std::make_pair(r1 - 1, c1 + 2));
		}
	}
	if(boundsCheck(r1 - 2,c1 + 1)){
		if(board->board[r1 - 2][c1 + 1]->piece->color != same){
    		coordinates.push_back(std::make_pair(r1 - 2, c1 + 1));
		}
	}
	if(boundsCheck(r1 - 2,c1 - 1)){
		if(board->board[r1 - 2][c1 - 1]->piece->color != same){
    		coordinates.push_back(std::make_pair(r1 - 2, c1 - 1));
		}
    }
    if(boundsCheck(r1 - 1,c1 - 2)){
		if(board->board[r1 - 1][c1 - 2]->piece->color != same){
    		coordinates.push_back(std::make_pair(r1 - 1, c1 - 2));
		}
	}
	if(boundsCheck(r1 + 1,c1 - 2)){
		if(board->board[r1 + 1][c1 - 2]->piece->color != same){
    		coordinates.push_back(std::make_pair(r1 + 1, c1 - 2));
		}
	}
	return coordinates;
}

/**
 * Generates the requested possible moves of the Rook, if the 
 * path is reachable. Returns a vector of coordinates.
 */

std::vector<std::pair<int, int> > Validator::generateRook(const Board* board, int r1, int c1, bool isBlack){
    std::vector<std::pair<int, int> > coordinates;
	PieceColor same = (isBlack) ? PieceColor::Black : PieceColor::White;

	//Forward
    for (int i=0; i<BOARD_SIZE-1; i++){
    	if(boundsCheck(r1 + i,c1)){
			if(board->board[r1 + i][c1]->piece->color != same){
    			coordinates.push_back(std::make_pair(r1 + i,c1));
    		} else {
    			break;
    		}
		}
    }
	//Reverse
    for (int i=0; i<BOARD_SIZE-1; i++){
    	if(boundsCheck(r1 - i,c1)){
			if(board->board[r1 - i][c1]->piece->color != same){
    			coordinates.push_back(std::make_pair(r1 - i,c1));
    		} else {
    			break;
    		}
		}
    }
	//Left
    for (int i=0; i<BOARD_SIZE-1; i++){
    	if(boundsCheck(r1,c1 - i)){
			if(board->board[r1][c1 - i]->piece->color != same){
    			coordinates.push_back(std::make_pair(r1,c1 - i));
    		} else {
    			break;
    		}
    	}
    }
	//Right
    for (int i=0; i<BOARD_SIZE-1; i++){
    	if(boundsCheck(r1,c1 + i)){
			if(board->board[r1][c1 + i]->piece->color != same){
    			coordinates.push_back(std::make_pair(r1,c1 + i));
    		} else {
    			break;
    		}
		}
    }
	return coordinates;
}

/**
 * Generates the requested possible moves of the Bishop, if the 
 * path is reachable. Returns a vector of coordinates.
 */

std::vector<std::pair<int, int> > Validator::generateBishop(const Board *board, int r1, int c1, bool isBlack){
    std::vector<std::pair<int, int> > coordinates;
	PieceColor same = (isBlack) ? PieceColor::Black : PieceColor::White;

	//Diagonal left fwd
    for (int i=0; i<BOARD_SIZE-1; i++){
    	if(boundsCheck(r1 + i,c1 + i)){
			if(board->board[r1+i][c1+i]->piece->color != same){
    			coordinates.push_back(std::make_pair(r1 + i,c1 + i));
    		} else {
    			break;
    		}
    	}
    }
	//Diagonal right reverse
    for (int i=0; i<BOARD_SIZE-1; i++){
    	if(boundsCheck(r1 - i,c1 + i)){
			if(board->board[r1 - i][c1 + i]->piece->color != same){
    			coordinates.push_back(std::make_pair(r1 - i,c1 + i));
    		} else {
    			break;
    		}
    	}
    }
	//Diagonal right fwd
    for (int i=0; i<BOARD_SIZE-1; i++){
    	if(boundsCheck(r1 + i,c1 - i)){
			if(board->board[r1+i][c1-i]->piece->color != same){
    			coordinates.push_back(std::make_pair(r1 + i,c1 - i));
    		} else {
    			break;
    		}
    	}
    }
	//Diagonal left rev
    for (int i=0; i<BOARD_SIZE-1; i++){
    	if(boundsCheck(r1 - i,c1 - i)){
			if(board->board[r1 + i][c1 - i]->piece->color != same){
    			coordinates.push_back(std::make_pair(r1 - i,c1 - i));
    		} else {
    			break;
    		}
    	}
    }
	return coordinates;
}

/**
 * Generates the requested possible moves of the Queen, if the 
 * path is reachable. Returns a vector of coordinates.
 */

std::vector<std::pair<int, int> > Validator::generateQueen(const Board *board, int r1, int c1, bool isBlack){
    std::vector<std::pair<int, int> > coordinates = this->generateRook(board, r1,c1, isBlack);
	std::vector<std::pair<int, int> > coordinates2 = this->generateBishop(board, r1,c1, isBlack);
	
	coordinates.reserve(coordinates2.size());
	coordinates.insert(coordinates.end(),coordinates2.begin(),coordinates2.end());
	coordinates2.clear();
	
	return coordinates;
}

/**
 * Generates the requested possible moves of the King, if the 
 * path is reachable. Returns a vector of coordinates.
 */

std::vector<std::pair<int, int> > Validator::generateKing(const Board *board, int r1, int c1, bool isBlack){
    std::vector<std::pair<int, int> > coordinates;
	PieceColor same = (isBlack) ? PieceColor::Black : PieceColor::White;

    if(boundsCheck(r1 + 1, c1)){
		if(board->board[r1 + 1][c1]->piece->color != same){
    		coordinates.push_back(std::make_pair(r1 + 1, c1));
		}
	}
	if(boundsCheck(r1 - 1,c1)){
		if(board->board[r1 - 1][c1]->piece->color != same){
    		coordinates.push_back(std::make_pair(r1 - 1, c1));
		}
	}
	if(boundsCheck(r1 + 1,c1 + 1)){
		if(board->board[r1 + 1][c1 + 1]->piece->color != same){
    		coordinates.push_back(std::make_pair(r1 + 1, c1 + 1));
		}
	}
	if(boundsCheck(r1 - 1,c1 + 1)){
		if(board->board[r1 - 1][c1 + 1]->piece->color != same){
    		coordinates.push_back(std::make_pair(r1 - 1, c1 + 1));
		}
	}
	if(boundsCheck(r1 + 1,c1 - 1)){
		if(board->board[r1 + 1][c1 - 1]->piece->color != same){
    		coordinates.push_back(std::make_pair(r1 + 1, c1 - 1));
		}
	}
	if(boundsCheck(r1 - 1,c1 - 1)){
		if(board->board[r1 - 1][c1 - 1]->piece->color != same){
    		coordinates.push_back(std::make_pair(r1 - 1, c1 - 1));
		}
    }
    if(boundsCheck(r1,c1 + 1)){
		if(board->board[r1][c1 + 1]->piece->color != same){
    		coordinates.push_back(std::make_pair(r1, c1 + 1));
		}
	}
	if(boundsCheck(r1,c1 - 1)){
		if(board->board[r1][c1 - 1]->piece->color != same){
    		coordinates.push_back(std::make_pair(r1, c1 - 1));
		}
	}
	return coordinates;
}


void Validator::doPopulate(const std::vector<std::pair<int, int> >& coordinates, bool isBlack){
	for (int i=0; i<coordinates.size(); i++){
		int row = coordinates[i].first;
		int col = coordinates[i].second;
		if(isBlack){
			this->attackWhite[row][col] = 0;
		} else {
			this->attackBlack[row][col] = 0;
		}
	}
	return;
}

void Validator::populateAttackMapPawn(const Board *board, int r1, int c1, bool isBlack){
	std::vector<std::pair<int, int> > coordinates = this->generatePawn(board, r1,c1,isBlack);
	//special case for pawn as it cannot attack in the forward direction
	coordinates.pop_back(); 
	this->doPopulate(coordinates, isBlack);
	return;
}

void Validator::populateAttackMapRook(const Board *board, int r1, int c1, bool isBlack){
	std::vector<std::pair<int, int> > coordinates = this->generateRook(board, r1,c1,isBlack);
	this->doPopulate(coordinates, isBlack);
	return;
}

void Validator::populateAttackMapBishop(const Board *board, int r1, int c1, bool isBlack){
	std::vector<std::pair<int, int> > coordinates = this->generateBishop(board, r1,c1,isBlack);
	this->doPopulate(coordinates, isBlack);
	return;
}

void Validator::populateAttackMapQueen(const Board *board, int r1, int c1, bool isBlack){
	std::vector<std::pair<int, int> > coordinates = this->generateQueen(board, r1,c1,isBlack);
	this->doPopulate(coordinates, isBlack);
	return;
}

void Validator::populateAttackMapKing(const Board *board, int r1, int c1, bool isBlack){
	std::vector<std::pair<int, int> > coordinates = this->generateKing(board, r1,c1,isBlack);
	this->doPopulate(coordinates, isBlack);
	return;
}

/**
 * Populates an attack map for a particular turn (color), given the current state of the
 * board and stores it in a 2D array called attackBlack/White corresponding to the turn.
 */
void Validator::populateAttackMap(const Board *board){
	//Clear and initialize the attack maps
	this->clear();
	this->initialize();


	//Check turn
	for (int row=0; row<BOARD_SIZE; row++){
		for (int col=0; col<BOARD_SIZE; col++){
			Piece *piece = board->board[row][col]->piece;
			
			//Populate only for pieces which are opposite to whose turn it is.
			if(board->turn != piece->color) {
				switch (piece->type){
					case PieceType::Pawn:
						if(board->turn == PieceColor::Black) {
							this->populateAttackMapPawn(board, row, col, 1);
						} else {
							this->populateAttackMapPawn(board, row, col, 0);
						}
					case PieceType::Rook:
						if(board->turn == PieceColor::Black) {
							this->populateAttackMapRook(board, row, col, 1);
						} else {
							this->populateAttackMapRook(board, row, col, 0);
						}
					case PieceType::Bishop:
						if(board->turn == PieceColor::Black) {
							this->populateAttackMapBishop(board, row, col, 1);
						} else {
							this->populateAttackMapBishop(board, row, col, 0);
						}
					case PieceType::Queen:
						if(board->turn == PieceColor::Black) {
							this->populateAttackMapQueen(board, row, col, 1);
						} else {
							this->populateAttackMapQueen(board, row, col, 0);
						}
					case PieceType::King:
						if(board->turn == PieceColor::Black) {
							this->populateAttackMapKing(board, row, col, 1);
						} else {
							this->populateAttackMapKing(board, row, col, 0);
						}
					default:
						return;
				}
			}
		}
	}

	return;
}

/**
 * Returns a vector of all Square*s which the piece in board->board[r1][c1]
 * can travel to.
 * TODO: AND attack map only for the king, for the rest of the pieces call generate and
 * make squares out of them.
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
    std::vector<std::pair<int, int> > coordinates = this->generateKnight(board, r1,c1, color);
    for (int i = 0; i < coordinates.size(); i++) {
        int row = coordinates[i].first;
        int col = coordinates[i].second;
        if (board->board[row][col]->piece->color == color) continue;
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

