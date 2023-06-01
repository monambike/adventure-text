#ifndef TERMINALUTILS_H
#define TERMINALUTILS_H

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

class TerminalUtils {
public:
    static void ChangeApplicationColor(Color color);
    static void ClearTerminal();
};

#endif