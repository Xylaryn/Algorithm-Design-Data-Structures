#include <iostream>
#include "Human.h"
#include "Computer.h"
#include "Referee.h"

int main() {
    Human player1("Mei");
    Computer player2;
    Referee referee;

    Player* winner = referee.refGame(&player1, &player2);

    if (winner == nullptr) {
        std::cout << "It's a Tie." << std::endl;
    } else {
        std::cout << winner->getName() << " Wins." << std::endl;
    }

    return 0;
}
