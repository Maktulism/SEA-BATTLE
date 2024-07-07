#ifndef CELL_H
#define CELL_H

class Cell {
public:
    Cell(int x, int y);
    int getX() const;
    int getY() const;
    bool isOccupied() const;
    void setOccupied(bool occupied);

private:
    int x;
    int y;
    bool occupied;
};

#endif // CELL_H
