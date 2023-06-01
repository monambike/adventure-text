#include <iostream>
#include "TerminalUtils.h"
#include "GameMessage.h"
#include "Player.h"
using namespace std;

Player mainPlayer;

int main() {
    TerminalUtils::ClearTerminal();

    GameMessage::WriteWelcomeMessage();
    GameMessage::AskForPlayerName(mainPlayer);
    
    TerminalUtils::ClearTerminal();
    cout << "Thank you so much " << mainPlayer.GetPlayerName() << "!";
    return 0;
}
