

#ifndef PIT_H
#define PIT_H

#include "Position.h"
#include "defs.h"
#include <vector>


#include "Participant.h" 

class Pit {
public:
    Pit(const char initialLayout[MAX_ROW+1][MAX_COL+1]); 
    bool withinBounds(int row, int col) const; 
    bool validPos(int row, int col) const; 
    bool underLedge(int row, int col) const; 
    void print(const std::vector<Participant*>& participants) const;

private:
    char layout[MAX_ROW+1][MAX_COL+1];
};

#endif
