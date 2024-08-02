#include "Pirate.h"
#include "Robot.h"
#include "Zombie.h"

// Implements the beats function for the child class Pirate
bool Pirate::beats(const Move& other) const {
    std::string otherName = other.getName();
    return otherName == "Robot" || otherName == "Zombie"; // Determines the moves that pirate beats
}