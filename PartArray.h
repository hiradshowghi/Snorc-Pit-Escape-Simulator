

#ifndef PARTARRAY_H
#define PARTARRAY_H

#include "Participant.h"

class PartArray {
public:
    PartArray(); 
    ~PartArray(); 
    void add(Participant* participant); 
    Participant* get(int index) const; 
    int size() const; 

private:
    static const int MAX_PARTICIPANTS = 100; 
    Participant* participants[MAX_PARTICIPANTS]; 
    int currentSize; 
};

#endif
