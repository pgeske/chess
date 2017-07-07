#include "Board.h"
#include "Validator.h"

Validator::Validator() {
    return;
}

Validator::~Validator() {
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
 * Generates all reachable moves for a Piece at the supplied coordinate.
 * Returns a vector of coordinates.
 */
std::vector<std::pair<int, int> > Validator::generate(const Board *board, int r1, int c1) {
    Piece *piece = board->board[r1][c1]->piece;
    bool isBlack = piece->color == PieceColor::Black ? true : false;
    switch (piece->type) {
        case PieceType::Pawn:
            return this->generatePawn(board, r1, c1, isBlack);
        case PieceType::Knight:
            return this->generateKnight(board, r1, c1, isBlack);
        case PieceType::Bishop:
            return this->generateBishop(board, r1, c1, isBlack);
        case PieceType::Rook:
            return this->generateRook(board, r1, c1, isBlack);
        case PieceType::Queen:
            return this->generateQueen(board, r1, c1, isBlack);
        case PieceType::King:
            return this->generateKing(board, r1, c1, isBlack);
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

