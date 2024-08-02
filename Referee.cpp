#include "Referee.h"

Referee::Referee() {}

// refGame function
Player* Referee::refGame(Player* player1, Player* player2) {
    Move* move1 = player1->makeMove();
    Move* move2 = player2->makeMove();

    if (move1->getName() == move2->getName()) {
        return nullptr; // tie
    } else if (move1->beats(*move2)) {
        return player1; // player 1 wins
    } else {
        return player2; // player 2 wins
    }
}
