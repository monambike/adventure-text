#include <iostream>
#include "GameMessage.h"
#include "Player.h"
#include "TerminalUtils.h"
using namespace std;

void GameMessage::WriteWelcomeMessage() {
    TerminalUtils::ClearTerminal();
    TerminalUtils::ChangeApplicationColor(White);
    cout << "Welcome to ";
    // Game title as red
    TerminalUtils::ChangeApplicationColor(Red);
    cout << "SUPER GAME SAGA";
    // Returning terminal color as white again
    TerminalUtils::ChangeApplicationColor(White);
    cout << "!" << endl
    << endl
    << "Please, insert the name you would want to be called for: ";
}

void GameMessage::AskForChangePlayerName() {
    string userInput;
    TerminalUtils::ChangeApplicationColor(Magenta);
    cin >> userInput;
    TerminalUtils::ChangeApplicationColor(White);
    mainPlayer.SetPlayerName(userInput);
}
