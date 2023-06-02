#include <iostream>
#include "Player.h"
#include "TerminalUtils.h"
using namespace std;

Player mainPlayer;

Player::Player() : name("Player Name"), life(3) {
    
}

void Player::DisplayPlayerName(){
    TerminalUtils::ChangeTerminalTextColor(Magenta);
    cout << name;
    TerminalUtils::ChangeTerminalTextColor(White);
}

string Player::GetPlayerName(){
    return name;
}

void Player::SetPlayerName(string newName){
    name = newName;
    cout << "[You have successfully changed your name for " << name << "]" << endl;
}

int Player::GetPlayerLife(){
    return life;
}