#include "Board.h"
#include <vector>

#ifndef _VALIDATOR_H_
#define _VALIDATOR_H_

class Validator {
    public:
        Validator();
        ~Validator();
        static bool validate(Board *board, int r1, int c1, int r2, int c2);
        std::vector<Square*> allowed(Board *board, int r1, int c1);
    private:
        void initialize();
        void clear();
		std::vector<std::pair<int, int> > generatePawn(const Board *board, int r1, int c1, bool isBlack);
		std::vector<std::pair<int, int> > generateRook(const Board *board, int r1, int c1, bool isBlack);
		std::vector<std::pair<int, int> > generateBishop(const Board *board, int r1, int c1, bool isBlack);
		std::vector<std::pair<int, int> > generateKnight(const Board *board, int r1, int c1, bool isBlack);
		std::vector<std::pair<int, int> > generateQueen(const Board *board, int r1, int c1, bool isBlack);
		std::vector<std::pair<int, int> > generateKing(const Board *board, int r1, int c1, bool isBlack);
        void populateAttackMap(const Board *board);
		void populateAttackMapPawn(const Board *board, int r1, int c1, bool isBlack);
		void populateAttackMapRook(const Board *board, int r1, int c1, bool isBlack);
		void populateAttackMapBishop(const Board *board, int r1, int c1, bool isBlack);
		void populateAttackMapKnight(const Board *board, int r1, int c1, bool isBlack);
		void populateAttackMapQueen(const Board *board, int r1, int c1, bool isBlack);
		void populateAttackMapKing(const Board *board, int r1, int c1, bool isBlack);
		void doPopulate(const std::vector<std::pair<int, int> >& coordinates, bool isBlack);
		bool boundsCheck(int r1, int c1);
        std::vector<Square*> allowedPawn(Board *board, int r1, int c1);
        std::vector<Square*> allowedRook(Board *board, int r1, int c1);
        std::vector<Square*> allowedBishop(Board *board, int r1, int c1);
        std::vector<Square*> allowedKnight(Board *board, int r1, int c1);
        std::vector<Square*> allowedQueen(Board *board, int r1, int c1);
        std::vector<Square*> allowedKing(Board *board, int r1, int c1);
        std::vector<std::vector<bool> > attackWhite; // possible attack positions of white pieces
        std::vector<std::vector<bool> > attackBlack; // possible attack positions of black pieces
};

#endif
