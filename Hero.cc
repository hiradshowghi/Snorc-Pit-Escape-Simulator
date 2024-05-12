#include "Hero.h"
#include "Participant.h"
#include "Pit.h"  

Hero::Hero(char avatar, int row, int col, const std::string& name)
    : Participant(avatar, row, col), name(name), health(MAX_HEALTH) {}

void Hero::move() {
    if (isDead() || isSafe()) {
        return;
    }
    int newRow = position->getRow();
    int newCol = position->getColumn();

    int moveType = random(100); 
    if (moveType < 50) { 
        newRow--; 
    } else if (moveType < 60) { 
        newRow -= 2; 
    } else { 
        newRow++; 
    }
    int horizontalMovement = random(5) - 2; 
    newCol += horizontalMovement;
    position->set(newRow, newCol);
}

void Hero::incurDamage(int damage) {
    health -= damage;
    if (health <= 0) {
        avatar = '+'; 
    }
}

int Hero::causeDamage() const {
    return 0; 
}

std::string Hero::getName() const {
    return name;
}

int Hero::getHealth() const {
    return health;
}

bool Hero::isDead() const {
    return health <= 0;
}

bool Hero::isSafe() const {
    return position->getRow() == 0;  
}


