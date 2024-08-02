#ifndef SCISSORS_H
#define SCISSORS_H

#include "Move.h"

// Scissors move class inheriting from the base class Move
class Scissors : public Move {
    public:
        std::string getName() const override { return "Scissors"; } // Returns the name of the move
        bool beats(const Move& other) const override; // Determines the moves that Scissors beat
};

#endif // SCISSORS_H
