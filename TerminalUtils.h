#ifndef TERMINALUTILS_H
#define TERMINALUTILS_H

#include <atomic>

using namespace std;

enum Color {
    Black,
    Red,
    Green,
    Yellow,
    Blue,
    Magenta,
    Cyan,
    White
};

extern std::atomic<bool> timerExpired;

class TerminalUtils {
public:
    static void ChangeTerminalTextColor(Color color);
    static void ClearTerminal();
    static void TimerThread(atomic<bool>& timerExpired, int seconds);
};

#endif