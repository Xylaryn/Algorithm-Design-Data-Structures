#include "Zombie.h"
#include "Rock.h"
#include "Scissors.h"

// Implements the beats function for child class Zombie
bool Zombie::beats(const Move& other) const {
    std::string otherName = other.getName();
    return otherName == "Rock" || otherName == "Scissors"; // determines the moves that Zombie beats which are Rock and Scissors
}
