// Copyright(c) 2023-present, Vinícius Gabriel (@monambike)
// Distributed under Creative Commons License (https://creativecommons.org/licenses/by/4.0/)

#include <conio.h>
#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include "event_actions.hpp"
#include "message.hpp"
#include "../entities/player_status.hpp"
#include "../utilities/terminal_utils.hpp"
using namespace std;

void GameEventActions::showQuestionMenu(string question) {
    cout << "<< " << question << " >>" << endl << endl;
}

void GameEventActions::showActionsMenu(string actions[numberOfActions]) {
    cout << "   ACTIONS" << endl;
    // Use the array
    for (int i = 0; i < numberOfActions; i++) {
        cout << i+1 << "] " << actions[i] << endl;
    }
}

void selectRandomEvent() {

}

int userSelectedAction;
void GameEventActions::triggerBaseEvent(string question, string actions[4]) {
    while (true) {
        TerminalUtils::clearTerminal();
        PlayerStatus::showGameStatusOnScreen();
        showQuestionMenu(question);
        showActionsMenu(actions);
        
        cout << "SELECT YOUR ACTION" << endl;
        userSelectedAction = _getch();

        // Check if the input is not a digit or is not between 1 and 4
        if (!isdigit(userSelectedAction) || userSelectedAction < '1' || userSelectedAction > '4') {
            // Clears the terminal and shows the title
            TerminalUtils::clearTerminal();
            TerminalUtils::changeTerminalTextColor(Red);
            
            GameMessage::showInvalidInputTimerMessage();
        } else {
            break;
        }
    }
}
