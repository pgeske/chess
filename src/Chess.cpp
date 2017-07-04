#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "Board.h"
#include "Piece.h"

using namespace std;

int main() {
    Board b = Board();
    b.start();
    b.execute(6, 0, 5, 0);
    b.draw_board();
//    for (int i = 0; i < 8; i++) {
//        for (int j = 0; j < 8; j++) {
//            if (b.board[i][j]->piece) {
//                cout << b.board[i][j]->piece->toString() << "\t";
//            } else {
//                cout << "0\t";
//            }
//        }
//        cout << endl;
//    }
    return 0;
}
