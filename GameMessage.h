#ifndef GAMEMESSAGE_H
#define GAMEMESSAGE_H

#include "Player.h"

class GameMessage {
public:
    static void showWelcomeMessage();
    static void askForChangePlayerName();
    static void showPressAnyKeyToContinueMessage();
    static void showInvalidInputTimerMessage();
    static void clearTerminalAndShowInvalidInputMessage();
};

#endif
