#ifndef PAPER_H
#define PAPER_H

#include "Move.h"

// Paper class inherits from Base class Move
class Paper : public Move {
    public:
        std::string getName() const override { return "Paper"; } // Returns the name of the move
        bool beats(const Move& other) const override; // Determines what move Paper beats
};

#endif // PAPER_H
