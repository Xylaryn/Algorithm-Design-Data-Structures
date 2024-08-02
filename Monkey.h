#ifndef MONKEY_H
#define MONKEY_H

#include "Move.h"

// Child class that inherits from base class called Move
class Monkey : public Move {
    public:
        std::string getName() const override { return "Monkey"; } // Returns the name of the played move
        bool beats(const Move& other) const override; // Determines the moves that Monkey beats
};

#endif // MONKEY_H
