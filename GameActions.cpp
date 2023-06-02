#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>
#include <conio.h>
#include <string>
#include "GameActions.h"
#include "GameMessage.h"
#include "TerminalUtils.h"
#include "PlayerStatus.h"
using namespace std;

void GameActions::ShowQuestionMenu(string question) {
    cout << "<< " << question << " >>" << endl << endl;
}

void GameActions::ShowActionsMenu(string actions[numberOfActions]) {
    cout << "   ACTIONS" << endl;
    // Use the array
    for (int i = 0; i < numberOfActions; i++) {
        cout << i+1 << "] " << actions[i] << endl;
    }
}


void SelectRandomEvent() {

}

void Event1() {

}

int userSelectedAction;
void GameActions::TriggerBaseEvent(string question, string actions[4]) {
    while (true) {
        TerminalUtils::ClearTerminal();
        PlayerStatus::ShowGameStatusOnScreen();
        ShowQuestionMenu(question);
        ShowActionsMenu(actions);
        
        cout << "SELECT YOUR ACTION" << endl;
        userSelectedAction = _getch();

        // Check if the input is not a digit or is not between 1 and 4
        if (!isdigit(userSelectedAction) || userSelectedAction < '1' || userSelectedAction > '4') {
            // Clears the terminal and shows the title
            TerminalUtils::ClearTerminal();
            TerminalUtils::ChangeTerminalTextColor(Red);
            
            GameMessage::ShowInvalidInputTimerMessage();
        } else {
            break;
        }
    }
}
