#include <iostream>
#include <conio.h>
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
    cout << "!" << endl;
    GameMessage::PressAnyKeyToContinue();
}

void GameMessage::AskForChangePlayerName() {
    // Asking for user input
    cout << endl << "Please, insert the ";
    TerminalUtils::ChangeApplicationColor(Yellow);
    cout << "name you would want to be called";
    TerminalUtils::ChangeApplicationColor(White);
    cout << " for: ";

    // User input, set terminal color to purple for enfatize
    // its name
    string userInput;
    TerminalUtils::ChangeApplicationColor(Magenta);
    cin >> userInput;

    // Set terminal color to white again and its name on character
    TerminalUtils::ChangeApplicationColor(White);
    mainPlayer.SetPlayerName(userInput);
}

void GameMessage::PressAnyKeyToContinue() {
    TerminalUtils::ChangeApplicationColor(Yellow);
    cout << endl << "Pess any key to continue...";
    TerminalUtils::ChangeApplicationColor(White);
    _getch(); // Waits for a keypress without requiring Enter
}
