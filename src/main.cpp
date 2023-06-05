// Copyright(c) 2023-present, Vinícius Gabriel (@monambike)
// Distributed under Creative Commons License (https://creativecommons.org/licenses/by/4.0/)

#include <iostream>
#include "GameComponents/GameActions.hpp"
#include "GameComponents/GameEvent.hpp"
#include "GameComponents/GameMessage.hpp"
#include "PlayerComponents/Player.hpp"
#include "PlayerComponents/PlayerStatus.hpp"
#include "Utilities/TerminalUtils.hpp"

int main() {
    TerminalUtils::clearTerminal();
    // Welcome message
    GameMessage::showWelcomeMessage();

    // Ask for user the name he would like to have
    TerminalUtils::clearTerminal();
    GameMessage::askForChangePlayerName();

    GameEvent::strangeCandyEvent();

    return 0;
}
