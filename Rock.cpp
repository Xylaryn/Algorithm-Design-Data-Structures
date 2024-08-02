#include "Rock.h"
#include "Scissors.h"
#include "Zombie.h"

// Implements the beats function for child class Rock
bool Rock::beats(const Move& other) const {
    std::string otherName = other.getName();
    return otherName == "Scissors" || otherName == "Zombie"; // determines the moves that rock beats
}
