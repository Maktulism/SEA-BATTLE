#include "tablecell.h"

TableCell::TableCell(int row, int column) : row(row), column(column) {}

int TableCell::getRow() const {
    return row;
}

int TableCell::getColumn() const {
    return column;
}
