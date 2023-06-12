// Copyright(c) 2023-present, Vinícius Gabriel (@monambike)
// Distributed under Creative Commons License (https://creativecommons.org/licenses/by/4.0/)

#ifndef GAMEMESSAGE_H
#define GAMEMESSAGE_H

#include "../entities/player.hpp"

class GameMessage {
private:
    static void startGameHomeScreen();
    static void showGameDescriptionText();
    static void showGameDescriptionScreen();
    static void showMenuPressAnyKeyToContinueMessageForWelcomeMessage();
public:
    // Home screen
    static void showWelcomeMessageAndWaitKeyPress();
    static void askForPlayerNameChange();
    // Press any key to continue
    static void showPressAnyKeyToContinueMessage();
    static void showInvalidInputTimerMessage();
    static void clearTerminalAndShowInvalidInputMessage();
};

#endif
