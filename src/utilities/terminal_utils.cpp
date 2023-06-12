// Copyright(c) 2023-present, Vinícius Gabriel (@monambike)
// Distributed under Creative Commons License (https://creativecommons.org/licenses/by/4.0/)

#include <atomic>
#include <chrono>
#include <iostream>
#include <thread>
#include "terminal_utils.hpp"

std::atomic<bool> timerExpired(false);

void TerminalUtils::changeTerminalTextColor(Color color) {
    switch (color) {
        case BLACK: cout << "\033[30m"; break;
        case RED: cout << "\033[31m"; break;
        case GREEN: cout << "\033[32m"; break;
        case YELLOW: cout << "\033[33m"; break;
        case BLUE: cout << "\033[34m"; break;
        case MAGENTA: cout << "\033[35m"; break;
        case CYAN: cout << "\033[36m"; break;
        case WHITE: default: cout << "\033[37m"; break; // Default color is white
    }
}

void TerminalUtils::clearTerminal() {
    cout << "\033[2J\033[1;1H"; // Clear terminal screen for most platforms, including VS Code's integrated terminal
    cout.flush();
}

void TerminalUtils::timerThread(atomic<bool>& timerExpired, int seconds) {
    // Sleep for 3 seconds
    this_thread::sleep_for(chrono::seconds(seconds));

    // Set the timerExpired flag to true
    timerExpired = true;
}
