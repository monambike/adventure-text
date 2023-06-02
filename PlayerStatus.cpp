#include <iostream>
#include "TerminalUtils.h"
#include "Player.h"
#include "PlayerStatus.h"
using namespace std;

void PlayerStatus::DisplayMajorLine() {
    cout << "------------------------------" << endl;
}

void PlayerStatus::DisplayUserLife(){
    cout << "Life Points:";
    int end = mainPlayer.GetPlayerLife();
    TerminalUtils::ChangeApplicationColor(Red);
    for (int i = 1; i <= end; i++) {
        cout << " ♥";
    }
    cout << endl << endl;
    TerminalUtils::ChangeApplicationColor(White);
}

void PlayerStatus::ShowGameStatusOnScreen() {
    DisplayMajorLine();
    cout << endl << "STATUS" << endl;
    mainPlayer.DisplayPlayerName();
    cout << endl;
    DisplayUserLife();
    DisplayMajorLine();
}
