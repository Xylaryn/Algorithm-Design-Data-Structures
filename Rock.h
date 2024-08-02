#ifndef ROCK_H
#define ROCK_H

#include "Move.h"

// Rock move class that inherits from Move base class
class Rock : public Move {
public:
    std::string getName() const override { return "Rock"; } // Returns the name of the move
    bool beats(const Move& other) const override; // Determines if Rock beats the other move played
};

#endif // ROCK_H
