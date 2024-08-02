#include "Ninja.h"
#include "Pirate.h"
#include "Zombie.h"

// Implements the beats function for the child class Ninja
bool Ninja::beats(const Move& other) const {
    std::string otherName = other.getName();
    return otherName == "Pirate" || otherName == "Zombie"; // Ninja beats the moves Pirate and Zombie
}
