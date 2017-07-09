#include "Board.h"
#include <vector>

#ifndef _VALIDATOR_H_
#define _VALIDATOR_H_

class Validator {
    public:
        Validator();
        ~Validator();
        static bool validate(Board *board, int r1, int c1, int r2, int c2);
        static std::vector<std::vector<int> > attackMap(const Board*, PieceColor);
    private:
		static std::vector<std::pair<int, int> > generate(const Board *board, int r1, int c1);
		static std::vector<std::pair<int, int> > generatePawn(const Board *board, int r1, int c1, bool isBlack);
		static std::vector<std::pair<int, int> > generateRook(const Board *board, int r1, int c1, bool isBlack);
		static std::vector<std::pair<int, int> > generateBishop(const Board *board, int r1, int c1, bool isBlack);
		static std::vector<std::pair<int, int> > generateKnight(const Board *board, int r1, int c1, bool isBlack);
		static std::vector<std::pair<int, int> > generateQueen(const Board *board, int r1, int c1, bool isBlack);
		static std::vector<std::pair<int, int> > generateKing(const Board *board, int r1, int c1, bool isBlack);
		static bool boundsCheck(int r1, int c1);
};

#endif
