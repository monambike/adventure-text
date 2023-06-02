#ifndef GAMEACTIONS_H
#define GAMEACTIONS_H

#include <iostream>
using namespace std;

class GameActions {
private:
    const static int numberOfActions = 4;
    static void ShowQuestionMenu(string question);
    static void ShowActionsMenu(string actions[numberOfActions]);
public:
    static void TriggerBaseEvent(string question, string actions[4]);
};

#endif
