#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Move.h"

// Abstract base class for players
class Player {
    public:
        virtual ~Player() = default; // Virtual destructor to cleanup derived classes after operation
        virtual Move* makeMove() = 0; // Virtual function to play a move
        virtual std::string getName() const = 0; 
};

#endif // PLAYER_H