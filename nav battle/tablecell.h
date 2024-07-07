#ifndef TABLECELL_H
#define TABLECELL_H

class TableCell {
public:
    TableCell(int row, int column);
    int getRow() const;
    int getColumn() const;

private:
    int row;
    int column;
};

#endif // TABLECELL_H
