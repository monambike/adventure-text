#include <iostream>
#include "Player.h"
#include "PlayerStatus.h"
#include "TerminalUtils.h"

void PlayerStatus::displayMajorLine() {
    cout << "==============================";
}

void PlayerStatus::displayUserLife(){
    cout << "Life Points:";
    int end = mainPlayer.getPlayerLife();
    TerminalUtils::changeTerminalTextColor(Red);
    for (int i = 1; i <= end; i++) {
        cout << " ♥";
    }
    cout << endl;
    TerminalUtils::changeTerminalTextColor(WHITE);
}

void PlayerStatus::showGameStatusOnScreen() {
    // Header line
    displayMajorLine();
    cout << endl << "            STATUS" << endl << endl;
    // Displaying player name line
    mainPlayer.displayPlayerName();
    cout << endl;
    // Displaying user life line
    displayUserLife();
    // Footer line
    displayMajorLine();
    cout << endl;
}
