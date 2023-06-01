#include <iostream>
#include "TerminalUtils.h"
#include "GameMessage.h"
#include "Player.h"
using namespace std;


Player mainPlayer;

void DisplayMajorLine() {
    cout << "------------------------------" << endl;
}

void DisplayUserLife(){
    cout << "Life Points:";
    int end = mainPlayer.GetPlayerLife();
    TerminalUtils::ChangeApplicationColor(Red);
    for (int i = 1; i <= end; i++) {
        cout << " ♥";
    }
    cout << endl << endl;
    TerminalUtils::ChangeApplicationColor(White);
}

void ShowGameStatusOnScreen() {
    DisplayMajorLine();
    cout << endl << "STATUS" << endl;
    cout << mainPlayer.GetPlayerName() << endl;
    DisplayUserLife();
    DisplayMajorLine();
}

int main() {
    GameMessage::WriteWelcomeMessage();
    GameMessage::AskForPlayerName(mainPlayer);

    TerminalUtils::ClearTerminal();
    ShowGameStatusOnScreen();
    cout << endl << "Thank you so much " << mainPlayer.GetPlayerName() << "!";
    return 0;
}
