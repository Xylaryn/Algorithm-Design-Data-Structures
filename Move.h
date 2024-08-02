#ifndef MOVE_H
#define MOVE_H

#include <string>

// Abstract base class for moves
class Move {
    public:
        virtual ~Move() = default; // Virtual destructor top clean up derived class
        virtual std::string getName() const = 0; // Virtual function to resolve the name of the move
        virtual bool beats(const Move& other) const = 0; // Additional virtual function to determine the outcome of the move
};

#endif // MOVE_H