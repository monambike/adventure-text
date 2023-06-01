#include <iostream>
#include "GameMessage.h"
#include "Player.h"
using namespace std;

void GameMessage::WriteWelcomeMessage() {
    cout
    << "Welcome to [game-name]!" << endl
    << endl
    << "Please, insert the name you would want to be called for: ";
}

void GameMessage::AskForPlayerName(Player player) {
    string userInput;
    cin >> userInput;
    player.ChangePlayerName(userInput);
}
