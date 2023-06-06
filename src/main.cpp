// Copyright(c) 2023-present, Vinícius Gabriel (@monambike)
// Distributed under Creative Commons License (https://creativecommons.org/licenses/by/4.0/)

#include <iostream>
#include "game/event_actions.hpp"
#include "game/event.hpp"
#include "game/message.hpp"
#include "entities/player.hpp"
#include "entities/player_status.hpp"
#include "utilities/terminal_utils.hpp"

int main() {
    // Showing welcome message
    TerminalUtils::clearTerminal();
    GameMessage::showWelcomeMessageAndWaitKeyPress();

    // Ask for user the name he would like to have
    TerminalUtils::clearTerminal();
    GameMessage::askForPlayerNameChange();

    // Starts the game
    GameEvent::strangeCandyEvent();

    return 0;
}
