#include "Monkey.h"
#include "Pirate.h"
#include "Ninja.h"

// Implements the beats function for the child class monkey
bool Monkey::beats(const Move& other) const {
    std::string otherName = other.getName();
    return otherName == "Pirate" || otherName == "Ninja"; // Determines the moves that monkey beats
}