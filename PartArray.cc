

#include "PartArray.h"
#include <cassert> 


PartArray::PartArray() : currentSize(0) {
    for (int i = 0; i < MAX_PARTICIPANTS; ++i) {
        participants[i] = nullptr; 
    }
}

PartArray::~PartArray() {
    for (int i = 0; i < currentSize; ++i) {
        participants[i] = nullptr;
    }
}

void PartArray::add(Participant* participant) {
    assert(currentSize < MAX_PARTICIPANTS); 
    participants[currentSize++] = participant; 
}

Participant* PartArray::get(int index) const {
    assert(index >= 0 && index < currentSize); 
    return participants[index]; 
}

int PartArray::size() const {
    return currentSize; 
}

