#ifndef ROBOT_H
#define ROBOT_H

#include "Move.h"

// Child class of the abstract class from Move
class Robot : public Move {
    public:
        std::string getName() const override { return "Robot"; } // Returns the name of the move
        bool beats(const Move& other) const override; // Determines the outcome of the move played
};

#endif // ROBOT_H
