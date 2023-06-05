#include <iostream>
#include "Player.h"
#include "TerminalUtils.h"
using namespace std;

Player mainPlayer;

Player::Player() : name("Player Name"), life(3) {
    
}

void Player::displayPlayerName(){
    TerminalUtils::changeTerminalTextColor(MAGENTA);
    cout << name;
    TerminalUtils::changeTerminalTextColor(WHITE);
}

std::string Player::getPlayerName(){
    return name;
}

void Player::setPlayerName(string newName){
    name = newName;
    cout << "[You have successfully changed your name for " << name << "]" << endl;
}

int Player::getPlayerLife(){
    return life;
}
