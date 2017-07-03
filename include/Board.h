#include "Square.h"
#include <vector>


class Board {
    public:
        Board();
        virtual ~Board();
        void initialize();
        void start();
        void clear();
        bool turn; // true if white, false if black
        std::vector<std::vector<Square*>> board; // the game board
        int execute(int r1, int c1, int r2, int c2);
    private:
        bool isValid(int r1, int c1, int r2, int c2);
};
