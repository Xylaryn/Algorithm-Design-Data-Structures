#include "Human.h"
#include <iostream>
#include "Rock.h"
#include "Paper.h"
#include "Scissors.h"
#include "Robot.h"
#include "Monkey.h"
#include "Pirate.h"
#include "Ninja.h"
#include "Zombie.h"

// Constructor that initialises the players moves
Human::Human(std::string name) : name(name) {}

// Implements the makeMove function for Player
Move* Human::makeMove() {
    std::string move;
    std::cout << "Enter move: ";
    std::cin >> move;

    if (move == "Rock") return new Rock();
    if (move == "Paper") return new Paper();
    if (move == "Scissors") return new Scissors();
    if (move == "Robot") return new Robot();
    if (move == "Monkey") return new Monkey();
    if (move == "Pirate") return new Pirate();
    if (move == "Ninja") return new Ninja();
    if (move == "Zombie") return new Zombie();

    std::cerr << "Invalid move entered." << std::endl;
    return nullptr; // invalid move
}

// Implements the getName function for players move
std::string Human::getName() const {
    return name;
}
