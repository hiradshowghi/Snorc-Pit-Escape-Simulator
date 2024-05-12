

#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include "Position.h"

class Participant {
public:
    Participant(char avatar, int row, int col);
    virtual ~Participant();
    virtual void move() = 0;
    virtual void incurDamage(int damage) = 0;
    virtual int causeDamage() const = 0;
    bool collide(const Participant& other) const;
    char getAvatar() const;
    int getRow() const;
    int getColumn() const;
    virtual bool isDead() const = 0;
    virtual bool isSafe() const = 0;
    
protected:
    char avatar;
    Position* position;
};

#endif
