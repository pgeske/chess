#include "Square.h"

Square::Square() {
    this->attackedWhite = false;
    this->attackedBlack = false;
    this->piece = 0;
    return;
}

Square::~Square() {
    delete this->piece;
    return;
}
