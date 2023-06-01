#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
using namespace std;

class Player {
public:
    string GetPlayerName();
    void ChangePlayerName(string name);
    int GetPlayerLife();
};

#endif
