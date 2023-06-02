#include <iostream>
#include "TerminalUtils.h"
#include "GameActions.h"
#include "GameMessage.h"
#include "Player.h"
#include "PlayerStatus.h"
using namespace std;


int main() {
    string actions[5] = {"Action 1", "Action 2", "Action 3", "Action 4"};
    GameActions::ShowActions(actions);
    // // Welcome message
    // GameMessage::WriteWelcomeMessage();
    
    // GameMessage::AskForChangePlayerName();

    // // Ask for user the name he would like to have
    // TerminalUtils::ClearTerminal();
    // PlayerStatus::ShowGameStatusOnScreen();

    // // Says "Thank you so much [player-name]!"
    // cout << endl << "Thank you so much ";
    // mainPlayer.DisplayPlayerName();
    // cout << "!";
    
    // return 0;
}
