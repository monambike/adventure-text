// Copyright(c) 2023-present, Vinícius Gabriel (@monambike)
// Distributed under Creative Commons License (https://creativecommons.org/licenses/by/4.0/)

#ifndef GAMEMESSAGE_H
#define GAMEMESSAGE_H

#include "../PlayerComponents/Player.hpp"

class GameMessage {
public:
    // Home screen
    static void showWelcomeMessage();
    static void askForChangePlayerName();

    // Press any key to continue
    static void showPressAnyKeyToContinueMessage();
    static void showInvalidInputTimerMessage();
    static void clearTerminalAndShowInvalidInputMessage();
};

#endif
