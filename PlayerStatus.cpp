#include <iostream>
#include "Player.h"
#include "PlayerStatus.h"
#include "TerminalUtils.h"

void PlayerStatus::DisplayMajorLine() {
    cout << "==============================";
}

void PlayerStatus::DisplayUserLife(){
    cout << "Life Points:";
    int end = mainPlayer.GetPlayerLife();
    TerminalUtils::ChangeTerminalTextColor(Red);
    for (int i = 1; i <= end; i++) {
        cout << " ♥";
    }
    cout << endl;
    TerminalUtils::ChangeTerminalTextColor(WHITE);
}

void PlayerStatus::ShowGameStatusOnScreen() {
    // Header line
    DisplayMajorLine();
    cout << endl << "            STATUS" << endl << endl;
    // Displaying player name line
    mainPlayer.DisplayPlayerName();
    cout << endl;
    // Displaying user life line
    DisplayUserLife();
    // Footer line
    DisplayMajorLine();
    cout << endl;
}
