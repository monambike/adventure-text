#ifndef GAMEMESSAGE_H
#define GAMEMESSAGE_H

#include "Player.h"
using namespace std;

class GameMessage {
public:
    static void WriteWelcomeMessage();
    static void AskForPlayerName(Player player);
};

#endif
