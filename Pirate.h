#ifndef PIRATE_H
#define PIRATE_H

#include "Move.h"

// Pirate move class inherits from the base class move
class Pirate : public Move {
    public:
        std::string getName() const override { return "Pirate"; } // Returns the name of the move
        bool beats(const Move& other) const override; // Determines the moves that pirates beats
};

#endif // PIRATE_H
