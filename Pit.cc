

#include "Pit.h"
#include <iostream>
#include "defs.h"  
#include <cstring> 

Pit::Pit(const char initialLayout[MAX_ROW + 1][MAX_COL + 1]) {
    memcpy(layout, initialLayout, sizeof(layout));
}

bool Pit::withinBounds(int row, int col) const {
    return row >= 0 && row <= MAX_ROW && col >= 0 && col <= MAX_COL;
}

bool Pit::validPos(int row, int col) const {
    return withinBounds(row, col) && layout[row][col] != '-';
}

bool Pit::underLedge(int row, int col) const {
    return row > 0 && withinBounds(row - 1, col) && layout[row - 1][col] == '-';
}

void Pit::print(const std::vector<Participant*>& participants) const {
    char display[MAX_ROW + 1][MAX_COL + 1];
    memcpy(display, layout, sizeof(display));  

    for (const auto& p : participants) {
        if (withinBounds(p->getRow(), p->getColumn())) {
            display[p->getRow()][p->getColumn()] = p->getAvatar();
        }
    }
    for (int row = 0; row <= MAX_ROW; ++row) {  
        for (int col = 0; col <= MAX_COL; ++col) {  
            std::cout << display[row][col];
        }
        std::cout << std::endl;
    }

    std::cout << "Timmy: " << //hero1->getHealth() 
        ", " << "Harold: " << /*hero2->getHealth()*/  std::endl;
}

