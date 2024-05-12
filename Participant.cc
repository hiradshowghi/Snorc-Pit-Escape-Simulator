#include "Participant.h"

Participant::Participant(char avatar, int row, int col) : avatar(avatar) {
    position = new Position(row, col);
}

Participant::~Participant() {
    delete position;
}

bool Participant::collide(const Participant& other) const {
    return this->position->equals(*(other.position));
}

char Participant::getAvatar() const {
    return avatar;
}

int Participant::getRow() const {
    return position->getRow();
}

int Participant::getColumn() const {
    return position->getColumn();
}


