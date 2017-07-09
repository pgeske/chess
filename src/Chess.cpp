#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "Board.h"
#include "Piece.h"
#include "Validator.h"

using namespace std;

int main() {
    Board *b = new Board();
    b->start();
    b->execute(6, 0, 5, 0);
    b->draw_board();
    Validator::attackMap(b, PieceColor::Black);
    /* vector<vector<int, int> > attackMap(b, PieceColor::Black); */
    delete b;
    return 0;
}
