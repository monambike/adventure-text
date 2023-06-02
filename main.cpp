#include <iostream>
#include "TerminalUtils.h"
#include "GameActions.h"
#include "GameMessage.h"
#include "Player.h"
#include "PlayerStatus.h"
using namespace std;

void StrangeCandyEvent() {
    string question = R"(A wild vendor appears and try to give you one mysterious candy. You
    have the option to accept it.)";
    string actions[] = {"Buy", "\"I'm not buying this!\"", "", "" };
    GameActions::TriggerBaseEvent(question, actions);
}

int main() {
    TerminalUtils::ClearTerminal();
    // Welcome message
    GameMessage::ShowWelcomeMessage();

    // Ask for user the name he would like to have
    TerminalUtils::ClearTerminal();
    GameMessage::AskForChangePlayerName();

    TerminalUtils::ClearTerminal();
    PlayerStatus::ShowGameStatusOnScreen();
    StrangeCandyEvent();
    // Says "Thank you so much [player-name]!"
    cout << endl << "Thank you so much ";
    mainPlayer.DisplayPlayerName();
    cout << "!";
    
    return 0;
}
