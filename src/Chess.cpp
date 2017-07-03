#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Board.h"

using namespace std;

int main() {
    Board b = Board();
    b.clear();
    b.initialize();
    b.clear();
    return 0;
}
