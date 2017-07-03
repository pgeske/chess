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
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (b.board[i][j]->piece) {
                cout << b.board[i][j]->piece->toString() << "\t";
                /* if (b.board[i][j]->piece->type == PieceType::Pawn) { */
                /*     cout << printType(b.board[i][j]->piece->type) << "\t"; */
                /* } */
            } else {
                cout << "0\t";
            }
        }
        cout << endl;
    }
    return 0;
}
