#include "Robot.h"
#include "Monkey.h"
#include "Zombie.h"

// Implements the beats function for the child class Robot
bool Robot::beats(const Move& other) const {
    std::string otherName = other.getName();
    return otherName == "Monkey" || otherName == "Zombie"; // Robot beats the move Monkey and Zombie
}