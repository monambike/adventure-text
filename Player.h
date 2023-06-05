#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
using namespace std;

class Player {
private:
    string name; // User can change player name
    int life; // If life reaches 0, then it's game over, life cannot be under 0

    string GetPlayerName();
public:
    Player();
    void DisplayPlayerName();
    void SetPlayerName(string name);

    int GetPlayerLife();
};

extern Player mainPlayer;

#endif
