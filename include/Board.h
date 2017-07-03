#include "Square.h"

class Board {
    public:
        Board();
        virtual ~Board();
    private:
        bool turn;
        Square[][] board;
};
