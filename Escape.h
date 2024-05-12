#ifndef ESCAPE_H
#define ESCAPE_H

#include "PartArray.h"
#include "Pit.h"
#include "Hero.h"
#include "Snorc.h"

class Escape {
public:
    Escape(); 
    ~Escape(); 
    void runEscape(); 
    bool isOver() const; 
    void spawnSnorc(); 

private:
    PartArray participants; 
    Pit* pit; 
    Hero* hero1; 
    Hero* hero2; 
    int numSnorcs;
    void moveParticipants(); 
    Participant* checkForCollision(Participant* participant); 
};

#endif
