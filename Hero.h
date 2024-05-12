

#ifndef HERO_H
#define HERO_H

#include "Participant.h"
#include <string>

class Hero : public Participant {
public:
    Hero(char avatar, int row, int col, const std::string& name); 
    virtual void move() override; 
    virtual void incurDamage(int damage) override; 
    virtual int causeDamage() const override; 
    std::string getName() const; 
    int getHealth() const; 
    virtual bool isDead() const override; 
    virtual bool isSafe() const override; 
    bool validPos(int row, int col) const;
    bool underLedge(int row, int col) const;
    

private:
    std::string name;
    int health;
};

#endif
