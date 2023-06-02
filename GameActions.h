#ifndef GAMEACTIONS_H
#define GAMEACTIONS_H

#include <iostream>
using namespace std;

class GameActions {
private:
    const static int numberOfActions = 4;
public:
    static void ShowQuestion(string question);
    static void ShowActions(string actions[numberOfActions]);
};

#endif
