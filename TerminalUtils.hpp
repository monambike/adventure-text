#ifndef TERMINALUTILS_H
#define TERMINALUTILS_H

#include <atomic>

using namespace std;

enum Color {
    BLACK,
    Red,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    WHITE
};

extern std::atomic<bool> timerExpired;

class TerminalUtils {
public:
    static void changeTerminalTextColor(Color color);
    static void clearTerminal();
    static void timerThread(atomic<bool>& timerExpired, int seconds);
};

#endif