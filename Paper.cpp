#include "Paper.h"
#include "Rock.h"
#include "Robot.h"

// Implements the beats function for the move played "Paper"
bool Paper::beats(const Move& other) const {
    std::string otherName = other.getName();
    return otherName == "Rock" || otherName == "Robot"; // Paper beats Rock and Robot moves
}
