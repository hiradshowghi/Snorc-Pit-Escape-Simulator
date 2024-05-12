#include <iostream>
using namespace std;
#include <string>
#include "Escape.h"
#include <cstdlib>  
#include <ctime>    


Escape::Escape()
{
  const char templateGrid[MAX_ROW+1][MAX_COL+1]={
      "-------------------------",
      "-             --        -",
      "-                      --",
      "-       --              -",
      "                  --    -",
      "--       -              -",
      "---                    --",
      "---       --          ---",
      "--                     --",
      "-            --        --",
      "---               --     ",
      "--        --    ---    --",
      "--  --                  -",
      "--        --       -     ",
      "--                  -    ",
      "--     --         --    -",
      "---                    --",
      "--       ---    --      -",
      "--                     --",
      "-------------------------"
      
  };
    srand(static_cast<unsigned>(time(nullptr)));
    pit = new Pit(templateGrid);
    hero1 = new Hero('T', MAX_ROW - 1, rand() % (MAX_COL - 2) + 1, "Timmy");  
    hero2 = new Hero('H', MAX_ROW - 1, rand() % (MAX_COL - 2) + 1, "Harold"); 
    while(hero1->getColumn() == hero2->getColumn()) { 
        hero2 = new Hero('H', MAX_ROW - 1, rand() % (MAX_COL - 2) + 1, "Harold");
    }
    participants.add(hero1);
    participants.add(hero2);

    numSnorcs = 0;
}


Escape::~Escape() {
    delete pit;  
}

void Escape::runEscape() {
    while (!isOver()) {
        moveParticipants();
        spawnSnorc();
        std::vector<Participant*> participantVector;

        for (int i = 0; i < participants.size(); ++i) {
            participantVector.push_back(participants.get(i));  
        }

        pit->print(participantVector);  
    }
}

bool Escape::isOver() const {
    return (hero1->isDead() || hero1->isSafe()) && (hero2->isDead() || hero2->isSafe());
}

void Escape::spawnSnorc() {
    if (numSnorcs < MAX_SNORCS) {
        int row = MAX_ROW - 5 + rand() % 5; 
        int col = rand() % MAX_COL;
        int strength = 2 + rand() % 3; 
        Snorc* newSnorc = new Snorc(row, col, strength);
        participants.add(newSnorc);
        newSnorc++;
    }
}

void Escape::moveParticipants() {
    for (int i = 0; i < participants.size(); ++i) {
        Participant* p = participants.get(i);
        if (p) { 
            p->move(); 
            Participant* collidedWith = checkForCollision(p);
            if (collidedWith) {
                p->incurDamage(collidedWith->causeDamage());
                collidedWith->incurDamage(p->causeDamage());
            }
        }
    }
}

Participant* Escape::checkForCollision(Participant* participant) {
    for (int i = 0; i < participants.size(); ++i) {
        Participant* other = participants.get(i);
        if (other && participant != other && participant->collide(*other)) {
            return other;
        }
    }
    return nullptr; 
}






