#include <iostream>
#include "TerminalUtils.h"
#include "GameMessage.h"
#include "Player.h"
#include "Status.h"
using namespace std;

int main() {
    // Welcome message
    GameMessage::WriteWelcomeMessage();
    GameMessage::AskForChangePlayerName();

    // Ask for user the name he would like to have
    TerminalUtils::ClearTerminal();
    Status::ShowGameStatusOnScreen();

    // Says "Thank you so much [player-name]!"
    cout << endl << "Thank you so much ";
    mainPlayer.DisplayPlayerName();
    cout << "!";
    
    return 0;
}
