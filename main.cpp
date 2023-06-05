#include <iostream>
#include "GameActions.h"
#include "GameMessage.h"
#include "Player.h"
#include "PlayerStatus.h"
#include "TerminalUtils.h"

void StrangeCandyEvent() {
    string question = R"(A wild vendor appears and try to give you one mysterious candy. You
    have the option to accept it.)";
    string actions[] = {"Buy", "\"I'm not buying this!\"", "", "" };
    GameActions::triggerBaseEvent(question, actions);
}

int main() {
    TerminalUtils::clearTerminal();
    // Welcome message
    GameMessage::showWelcomeMessage();

    // Ask for user the name he would like to have
    TerminalUtils::clearTerminal();
    GameMessage::askForChangePlayerName();

    StrangeCandyEvent();
    
    return 0;
}
