

#include "Position.h"
#include "defs.h" 


Position::Position(int row, int col) {
    set(row, col); 
}

void Position::set(int newRow, int newCol) {
    if (newRow < 0) {
        this->row = 0;
    } else if (newRow >= MAX_ROW) {
        this->row = MAX_ROW - 1;
    } else {
        this->row = newRow;
    }
    if (newCol < 0) {
        this->column = 0;
    } else if (newCol >= MAX_COL) {
        this->column = MAX_COL - 1;
    } else {
        this->column = newCol;
    }
}

int Position::getRow() const {
    return row;
}

int Position::getColumn() const {
    return column;
}

bool Position::equals(const Position &other) const {
    return this->row == other.row && this->column == other.column;
}
