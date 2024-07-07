#include "cell.h"

Cell::Cell(int x, int y) : x(x), y(y), occupied(false) {}

int Cell::getX() const {
    return x;
}

int Cell::getY() const {
    return y;
}

bool Cell::isOccupied() const {
    return occupied;
}

void Cell::setOccupied(bool occupied) {
    this->occupied = occupied;
}
