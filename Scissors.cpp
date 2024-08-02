#include "Scissors.h"
#include "Paper.h"
#include "Monkey.h"

// Implements the beats function for child class Scissors
bool Scissors::beats(const Move& other) const {
    std::string otherName = other.getName();
    return otherName == "Paper" || otherName == "Monkey"; // Scissors beats Paper and Monkey
}
