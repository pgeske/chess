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
    printf("%d\n", b->execute(6, 0, 5, 0));
    b->draw_board();
    bool valid = Validator::validate(b, 1, 1, 2, 1); 
    delete b;
    return 0;
}
