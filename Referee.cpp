#include "Referee.h"
#include <iostream>

// Defualt Constructor for referee class
Referee::Referee() {}

// refGame function
Player* Referee::refGame(Player* player1, Player* player2) {
    Move* move1 = player1->makeMove();
    Move* move2 = player2->makeMove();

    // Input validation
    if (move1 == nullptr || move2 == nullptr) {
        std::cerr << "Invalid move. Exiting game." << std::endl;
        return nullptr;
    }

    std::cout << player1->getName() << " chose " << move1->getName() << std::endl;
    std::cout << player2->getName() << " chose " << move2->getName() << std::endl;

    if (move1->getName() == move2->getName()) {
        return nullptr; // tie
    } else if (move1->beats(*move2)) {
        return player1; // player 1 wins
    } else {
        return player2; // player 2 wins
    }
}
