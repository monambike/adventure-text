#include <iostream>
#include "Player.h"
using namespace std;

int life = 100; // If life reaches 0, then it's game over, life cannot be under 0
string name = "Player Name"; // User can change player name

string Player::GetPlayerName(){
    return name;
}

void Player::ChangePlayerName(string name){
    name = name;
    cout << "[You have successfully changed your name for " << name << "]" << endl;
}
