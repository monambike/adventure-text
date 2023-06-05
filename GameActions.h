#ifndef GAMEACTIONS_H
#define GAMEACTIONS_H

#include <iostream>

class GameActions {
private:
    const static int numberOfActions = 4;
    static void ShowQuestionMenu(std::string question);
    static void ShowActionsMenu(std::string actions[numberOfActions]);
public:
    static void TriggerBaseEvent(std::string question, std::string actions[4]);
};

#endif
