#include "Square.h"
#include <vector>


class Board {
    public:
        Board();
        virtual ~Board();
        bool getTurn();
        void setTurn(bool turn);
        void initialize();
    private:
        bool turn; // true if white, false if black
        std::vector<std::vector<Square*>> board;
};
