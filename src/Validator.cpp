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
    PieceColor opposite = board->turn == PieceColor::Black ? PieceColor::White : PieceColor::Black;
    // Check bounds for source
    if (!Validator::boundsCheck(r1, c1)) return false;
    // Ensure source piece is the correct color
    Piece *piece = board->board[r1][c1]->piece;
    if (piece->color != board->turn) return false;
    // See if r2, c2 is a reachable coordinate. If not, move is invalid.
    std::vector<std::pair<int, int> > reachable = Validator::generate(board, r1, c1);
    bool canReach = false;
    for (auto it = reachable.begin(); it != reachable.end(); ++it) {
        if ((*it).first == r2 && (*it).second == c2) canReach = true;
    }
    if (!canReach) return false;
    // Move the piece
    Square *source = board->board[r1][c1];
    Square *dest = board->board[r2][c2];
    Piece *tmp = dest->liftPiece();
    dest->piece = source->liftPiece();
    // See if King is under attack. If so, move is invalid.
    bool kingUnderAttack = false;
    std::vector<std::vector<int> > attackMap = Validator::attackMap(board, opposite);
    for (int i = 0; i < board->board.size(); i++) {
        for (int j = 0; j < board->board[i].size(); j++) {
            Piece *piece = board->board[i][j]->piece;
            if (piece->type == PieceType::King && piece->color == board->turn) {
                if (attackMap[i][j]) kingUnderAttack = true;
            }
        }
    }
    // Undo the move
    source->piece = dest->liftPiece();
    dest->piece = tmp;
    return !kingUnderAttack;
}


bool Validator::boundsCheck(int r1, int c1){
    if(r1>=0 && r1<BOARD_SIZE && c1>=0 && c1<BOARD_SIZE){
        return 1;
    } else {
        return 0;
    }
}

/**
 * Returns a 2D vector representing an attack map. An entry is 1 if the 
 * corresponding square is under attack by the specified PieceColor. Otherwise,
 * it is 0.
 */
std::vector<std::vector<int> > Validator::attackMap(const Board *board, PieceColor color) {
    std::vector<std::vector<int> > attackMap;
    for (int i = 0; i < BOARD_SIZE; i++) {
        attackMap.push_back(std::vector<int>());
        for (int j = 0; j < BOARD_SIZE; j++) {
            attackMap[i].push_back(0);
        }
    }
    for (int i = 0; i < board->board.size(); i++) {
        for (int j = 0; j < board->board.size(); j++) {
            Piece *piece = board->board[i][j]->piece;
            if (piece->color == color) continue;
            std::vector<std::pair<int, int> > reachable = Validator::generate(board, i, j);
            for (int i = 0; i < reachable.size(); i++) {
                std::pair<int, int> coord = reachable[i];
                // For Pawn, not all reachable squares are attackable
                if (piece->type == PieceType::Pawn && coord.second == j) continue;
                attackMap[coord.first][coord.second] = 1;
            }
        }
    }
    return attackMap;
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
            return Validator::generatePawn(board, r1, c1, isBlack);
        case PieceType::Knight:
            return Validator::generateKnight(board, r1, c1, isBlack);
        case PieceType::Bishop:
            return Validator::generateBishop(board, r1, c1, isBlack);
        case PieceType::Rook:
            return Validator::generateRook(board, r1, c1, isBlack);
        case PieceType::Queen:
            return Validator::generateQueen(board, r1, c1, isBlack);
        case PieceType::King:
            return Validator::generateKing(board, r1, c1, isBlack);
    }
    return std::vector<std::pair<int, int> >();
}

/**
 * Generates the requested possible moves of the Pawn, if the 
 * path is reachable. Returns a vector of coordinates.
 */

std::vector<std::pair<int, int> > Validator::generatePawn(const Board* board, int r1, int c1, bool isBlack){
    std::vector<std::pair<int, int> > coordinates;
    PieceColor same = (isBlack) ? PieceColor::Black : PieceColor::White;
    PieceColor opposite = (isBlack) ? PieceColor::White : PieceColor::Black;
    int direction = isBlack ? 1 : -1;
    if (Validator::boundsCheck(r1 + direction, c1 + 1)) {
        if(board->board[r1 + direction][c1 + 1]->piece->color == opposite){
            coordinates.push_back(std::make_pair(r1 + direction, c1 + 1));
        }
    }
    if(Validator::boundsCheck(r1 + direction, c1 - 1)){
        if(board->board[r1 + direction][c1 - 1]->piece->color == opposite){
            coordinates.push_back(std::make_pair(r1 + direction, c1 - 1));
        }
    }
    if(Validator::boundsCheck(r1 + direction,c1)){
        if(board->board[r1 + direction][c1]->piece->color != same){
            coordinates.push_back(std::make_pair(r1 + direction, c1));
        }
    }
    if (isBlack && r1 == 1) {
        if (board->board[r1 + 2][c1]->piece->color != same) {
            coordinates.push_back(std::make_pair(r1 + 2, c1));
        }
    }
    if (!isBlack && r1 == 6) {
        if (board->board[r1 - 2][c1]->piece->color != same) {
            coordinates.push_back(std::make_pair(r1 - 2, c1));
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

    if(Validator::boundsCheck(r1 + 2, c1 - 1)){
        if(board->board[r1 + 2][c1 - 1]->piece->color != same){
            coordinates.push_back(std::make_pair(r1 + 2, c1 - 1));
        }
    }
    if(Validator::boundsCheck(r1 + 2,c1 + 1)){
        if(board->board[r1 + 2][c1 + 1]->piece->color != same){
            coordinates.push_back(std::make_pair(r1 + 2, c1 + 1));
        }
    }
    if(Validator::boundsCheck(r1 + 1,c1 + 2)){
        if(board->board[r1 + 1][c1 + 2]->piece->color != same){
            coordinates.push_back(std::make_pair(r1 + 1, c1 + 2));
        }
    }
    if(Validator::boundsCheck(r1 - 1,c1 + 2)){
        if(board->board[r1 - 1][c1 + 2]->piece->color != same){
            coordinates.push_back(std::make_pair(r1 - 1, c1 + 2));
        }
    }
    if(Validator::boundsCheck(r1 - 2,c1 + 1)){
        if(board->board[r1 - 2][c1 + 1]->piece->color != same){
            coordinates.push_back(std::make_pair(r1 - 2, c1 + 1));
        }
    }
    if(Validator::boundsCheck(r1 - 2,c1 - 1)){
        if(board->board[r1 - 2][c1 - 1]->piece->color != same){
            coordinates.push_back(std::make_pair(r1 - 2, c1 - 1));
        }
    }
    if(Validator::boundsCheck(r1 - 1,c1 - 2)){
        if(board->board[r1 - 1][c1 - 2]->piece->color != same){
            coordinates.push_back(std::make_pair(r1 - 1, c1 - 2));
        }
    }
    if(Validator::boundsCheck(r1 + 1,c1 - 2)){
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
        if(Validator::boundsCheck(r1 + i,c1)){
            if(board->board[r1 + i][c1]->piece->color != same){
                coordinates.push_back(std::make_pair(r1 + i,c1));
            } else {
                break;
            }
        }
    }
    //Reverse
    for (int i=0; i<BOARD_SIZE-1; i++){
        if(Validator::boundsCheck(r1 - i,c1)){
            if(board->board[r1 - i][c1]->piece->color != same){
                coordinates.push_back(std::make_pair(r1 - i,c1));
            } else {
                break;
            }
        }
    }
    //Left
    for (int i=0; i<BOARD_SIZE-1; i++){
        if(Validator::boundsCheck(r1,c1 - i)){
            if(board->board[r1][c1 - i]->piece->color != same){
                coordinates.push_back(std::make_pair(r1,c1 - i));
            } else {
                break;
            }
        }
    }
    //Right
    for (int i=0; i<BOARD_SIZE-1; i++){
        if(Validator::boundsCheck(r1,c1 + i)){
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
        if(Validator::boundsCheck(r1 + i,c1 + i)){
            if(board->board[r1+i][c1+i]->piece->color != same){
                coordinates.push_back(std::make_pair(r1 + i,c1 + i));
            } else {
                break;
            }
        }
    }
    //Diagonal right reverse
    for (int i=0; i<BOARD_SIZE-1; i++){
        if(Validator::boundsCheck(r1 - i,c1 + i)){
            if(board->board[r1 - i][c1 + i]->piece->color != same){
                coordinates.push_back(std::make_pair(r1 - i,c1 + i));
            } else {
                break;
            }
        }
    }
    //Diagonal right fwd
    for (int i=0; i<BOARD_SIZE-1; i++){
        if(Validator::boundsCheck(r1 + i,c1 - i)){
            if(board->board[r1+i][c1-i]->piece->color != same){
                coordinates.push_back(std::make_pair(r1 + i,c1 - i));
            } else {
                break;
            }
        }
    }
    //Diagonal left rev
    for (int i=0; i<BOARD_SIZE-1; i++){
        if(Validator::boundsCheck(r1 - i,c1 - i)){
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
    std::vector<std::pair<int, int> > coordinates = Validator::generateRook(board, r1,c1, isBlack);
    std::vector<std::pair<int, int> > coordinates2 = Validator::generateBishop(board, r1,c1, isBlack);

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

    if(Validator::boundsCheck(r1 + 1, c1)){
        if(board->board[r1 + 1][c1]->piece->color != same){
            coordinates.push_back(std::make_pair(r1 + 1, c1));
        }
    }
    if(Validator::boundsCheck(r1 - 1,c1)){
        if(board->board[r1 - 1][c1]->piece->color != same){
            coordinates.push_back(std::make_pair(r1 - 1, c1));
        }
    }
    if(Validator::boundsCheck(r1 + 1,c1 + 1)){
        if(board->board[r1 + 1][c1 + 1]->piece->color != same){
            coordinates.push_back(std::make_pair(r1 + 1, c1 + 1));
        }
    }
    if(Validator::boundsCheck(r1 - 1,c1 + 1)){
        if(board->board[r1 - 1][c1 + 1]->piece->color != same){
            coordinates.push_back(std::make_pair(r1 - 1, c1 + 1));
        }
    }
    if(Validator::boundsCheck(r1 + 1,c1 - 1)){
        if(board->board[r1 + 1][c1 - 1]->piece->color != same){
            coordinates.push_back(std::make_pair(r1 + 1, c1 - 1));
        }
    }
    if(Validator::boundsCheck(r1 - 1,c1 - 1)){
        if(board->board[r1 - 1][c1 - 1]->piece->color != same){
            coordinates.push_back(std::make_pair(r1 - 1, c1 - 1));
        }
    }
    if(Validator::boundsCheck(r1,c1 + 1)){
        if(board->board[r1][c1 + 1]->piece->color != same){
            coordinates.push_back(std::make_pair(r1, c1 + 1));
        }
    }
    if(Validator::boundsCheck(r1,c1 - 1)){
        if(board->board[r1][c1 - 1]->piece->color != same){
            coordinates.push_back(std::make_pair(r1, c1 - 1));
        }
    }
    return coordinates;
}

