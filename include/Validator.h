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
};

#endif
