#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>
#include <conio.h>
#include "GameActions.h"
#include "GameMessage.h"
#include "TerminalUtils.h"
using namespace std;

void GameActions::ShowQuestion(string question) {
    cout << question;

}

void GameActions::ShowActions(string actions[numberOfActions]) {
    cout << "[ACTIONS]" << endl;
    // Use the array
    for (int i = 0; i < numberOfActions; i++) {
        cout << i+1 << " - " << actions[i] << endl;
    }


    cout << "Select your action" << endl;
    int userInput = _getch();

    // Check if the input is not a digit or is not between 1 and 4
    if (!isdigit(userInput) || userInput < '1' || userInput > '4') {
        // Clears the terminal and shows the title
        TerminalUtils::ClearTerminal();
        TerminalUtils::ChangeApplicationColor(Red);
        cout << "INVALID INPUT";

        // Body message
        TerminalUtils::ChangeApplicationColor(White);
        cout << endl << endl << "Please enter a digit between 1 and 4." << endl;   

        // Waiting for user input
        GameMessage::PressAnyKeyToContinue();
    }
}
