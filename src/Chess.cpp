#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "Board.h"
#include "Piece.h"

using namespace std;

string printType(PieceType t) {
    if (t == PieceType::Pawn) {
        return "PAWN";
    } else if (t == PieceType::Knight) {
        return "KNIGHT";
    } else if (t == PieceType::Bishop) {
        return "BISHOP";
    } else if (t == PieceType::King) {
        return "KING";
    } else if (t == PieceType::Queen) {
        return "QUEEN";
    } else  if (t == PieceType::Rook) {
        return "ROOK";
    }
}

int main() {
    string test = "hello";
    Board b = Board();
    b.start();
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            if (b.board[i][j]->piece) {
                if (b.board[i][j]->piece->type == PieceType::Pawn) {
                    cout << printType(b.board[i][j]->piece->type) << "\t";
                }
            } else {
                cout << "0\t";
            }
        }
        cout << endl;
    }
    return 0;
}
