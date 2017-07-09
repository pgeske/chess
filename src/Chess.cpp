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
    bool valid = Validator::validate(b, 1, 1, 2, 1); 
    /* vector<vector<int> > amap = Validator::attackMap(b, PieceColor::Black); */
    /* for (int i = 0; i < amap.size(); i++) { */
    /*     for (int j = 0; j < amap[i].size(); j++) { */
    /*         printf("%d\t", amap[i][j]); */
    /*     } */
    /*     printf("\n"); */
    /* } */
    delete b;
    return 0;
}
