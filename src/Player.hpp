// Copyright(c) 2023-present, Vinícius Gabriel (@monambike)
// Distributed under Creative Commons License (https://creativecommons.org/licenses/by/4.0/)

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

class Player {
private:
    std::string name; // User can change player name
    int life; // If life reaches 0, then it's game over, life cannot be under 0

    std::string getPlayerName();
public:
    Player();
    void displayPlayerName();
    void setPlayerName(std::string name);

    int getPlayerLife();
};

extern Player mainPlayer;

#endif
