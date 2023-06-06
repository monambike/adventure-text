// Copyright(c) 2023-present, Vinícius Gabriel (@monambike)
// Distributed under Creative Commons License (https://creativecommons.org/licenses/by/4.0/)

#include <iostream>
#include "Player.hpp"
#include "../utilities/terminal_utils.hpp"
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
