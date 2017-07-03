#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Board.h"

using namespace std;

int main() {
    int* test;
    test = new int[10];
    for (int i = 0; i < 10; i++) {
        test[i] = 1;
        cout << test[i] << endl;
    }
    delete test;
    puts("HELLO WORLD");
    return 0;
}
