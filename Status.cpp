#include <iostream>
#include "TerminalUtils.h"
#include "Player.h"
#include "Status.h"
using namespace std;

void Status::DisplayMajorLine() {
    cout << "------------------------------" << endl;
}

void Status::DisplayUserLife(){
    cout << "Life Points:";
    int end = mainPlayer.GetPlayerLife();
    TerminalUtils::ChangeApplicationColor(Red);
    for (int i = 1; i <= end; i++) {
        cout << " ♥";
    }
    cout << endl << endl;
    TerminalUtils::ChangeApplicationColor(White);
}

void Status::ShowGameStatusOnScreen() {
    DisplayMajorLine();
    cout << endl << "STATUS" << endl;
    cout << mainPlayer.GetPlayerName() << endl;
    DisplayUserLife();
    DisplayMajorLine();
}
