#include <iostream>
#include "TerminalUtils.h"
#include "GameMessage.h"
#include "Player.h"
#include "Status.h"
using namespace std;

extern Player mainPlayer;
Player mainPlayer;

int main() {
    GameMessage::WriteWelcomeMessage();
    GameMessage::AskForPlayerName(mainPlayer);

    TerminalUtils::ClearTerminal();
    Status::ShowGameStatusOnScreen();
    cout << endl << "Thank you so much " << mainPlayer.GetPlayerName() << "!";
    return 0;
}
