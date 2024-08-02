#ifndef REFEREE_H
#define REFEREE_H

#include "Player.h"

class Referee {
    public:
        Referee(); // Contructor for the referee child class
        Player* refGame(Player* player1, Player* player2); // Determines the winner of the game based on the played move
};

#endif // REFEREE_H
