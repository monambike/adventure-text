#ifndef GAMEMESSAGE_H
#define GAMEMESSAGE_H

#include "Player.hpp"

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
