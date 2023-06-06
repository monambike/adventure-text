// Copyright(c) 2023-present, Vinícius Gabriel (@monambike)
// Distributed under Creative Commons License (https://creativecommons.org/licenses/by/4.0/)

#ifndef GAMEEVENTACTIONS_H
#define GAMEEVENTACTIONS_H

#include <iostream>

class GameEventActions {
private:
    const static int numberOfActions = 4;
    static void showQuestionMenu(std::string question);
    static void showActionsMenu(std::string actions[numberOfActions]);
public:
    static void triggerBaseEvent(std::string question, std::string actions[4]);
};

#endif
