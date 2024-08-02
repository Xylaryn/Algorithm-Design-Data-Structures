#include "Computer.h"
#include "Rock.h" // Computer will always play Rock for simplicity

// Implements the makeMove function for child class Computer
Move* Computer::makeMove() {
    return new Rock();
}

// Implements the getName function for child class Computer
std::string Computer::getName() const {
    return "Computer";
}
