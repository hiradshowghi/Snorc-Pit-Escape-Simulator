

#ifndef SNORC_H
#define SNORC_H

#include "Participant.h"

class Snorc : public Participant {
public:
    Snorc(int row, int col, int strength);
    virtual ~Snorc() override = default;
    virtual void move() override;
    virtual void incurDamage(int damage) override;
    virtual int causeDamage() const override;
    virtual bool isDead() const override;
    virtual bool isSafe() const override;
    bool withinBounds(int row, int col) const;
private:
    int strength;
    bool dead; 
};

#endif
