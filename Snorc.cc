#include "Participant.h"
#include "Snorc.h"
#include "Pit.h" 


Snorc::Snorc(int row, int col, int strength)
    : Participant('s', row, col), 
      strength(strength) {}

void Snorc::move() {
    int newRow = position->getRow() + random(3) - 1; 
    int newCol = position->getColumn() + random(3) - 1; 

    if (newRow >= MAX_ROW - 7) {
        newRow = position->getRow();
    }
    position->set(newRow, newCol);
}

void Snorc::incurDamage(int damage) {}

int Snorc::causeDamage() const {
    return strength; 
}

bool Snorc::isDead() const {
    return false; 
}

bool Snorc::isSafe() const {
    return false;
}

