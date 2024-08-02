#ifndef NINJA_H
#define NINJA_H

#include "Move.h"

class Ninja : public Move {
    public:
        std::string getName() const override { return "Ninja"; } // Returns the name of the move
        bool beats(const Move& other) const override; // Determines the moves that ninja beats
};

#endif // NINJA_H