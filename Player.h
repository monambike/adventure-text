#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

class Player {
private:
    std::string name; // User can change player name
    int life; // If life reaches 0, then it's game over, life cannot be under 0

    std::string GetPlayerName();
public:
    Player();
    void DisplayPlayerName();
    void SetPlayerName(std::string name);

    int GetPlayerLife();
};

extern Player mainPlayer;

#endif
