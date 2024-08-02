#ifndef COMPUTER_H
#define COMPUTER_H

#include "Player.h"
#include <string>

// Computer player class inheriting from base class Player
class Computer : public Player {
public:
    Move* makeMove() override; 
    std::string getName() const override; 
};

#endif // COMPUTER_H
