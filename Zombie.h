#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "Move.h"

// Zombie move class which inherits from base class Move
class Zombie : public Move {
public:
    std::string getName() const override { return "Zombie"; } // Returns the name of the move played
    bool beats(const Move& other) const override; // Determines the moves that Zombie beats
};

#endif // ZOMBIE_H
