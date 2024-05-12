

#ifndef POSITION_H
#define POSITION_H

class Position {
public:
    Position(int row, int col);
    void set(int newRow, int newCol);
    int getRow() const; 
    int getColumn() const;
    bool equals(const Position &other) const;

private:
    int row;
    int column;
};

#endif
