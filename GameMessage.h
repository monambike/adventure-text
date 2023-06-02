#ifndef GAMEMESSAGE_H
#define GAMEMESSAGE_H

#include "Player.h"
using namespace std;

class GameMessage {
public:
    static void ShowWelcomeMessage();
    static void AskForChangePlayerName();
    static void ShowPressAnyKeyToContinueMessage();
    static void ShowInvalidInputTimerMessage();
    static void ClearTerminalAndShowInvalidInputMessage();
};

#endif
