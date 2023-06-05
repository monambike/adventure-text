#include <chrono>
#include <conio.h>
#include <iostream>
#include <thread>
#include "GameMessage.hpp"
#include "Player.hpp"
#include "TerminalUtils.hpp"

void showGameDescription() {
    std::cout << R"(
In this game, you will embark on a captivating journey through many
adventures.
Your choices will shape the destiny of your character and the outcome
of the game.

This is a small game created to learn and explore the essentials of C++
and the powerful capabilities it provides.

Enjoy the adventure and let the history unfold!
    )";

    
    int pressedKey = _getch();
    if (pressedKey == 8) { // Tab key is pressed
        cout << "Return to main menu";
    }
}

void GameMessage::clearTerminalAndShowInvalidInputMessage() {
    TerminalUtils::clearTerminal();
    TerminalUtils::changeTerminalTextColor(Red);
    std::cout << "INVALID INPUT" << endl << endl;;
    TerminalUtils::changeTerminalTextColor(WHITE);
    std::cout << "This option it's not a valid input, please select an option from ";
    TerminalUtils::changeTerminalTextColor(Red);
    std::cout << "list of actions";
    TerminalUtils::changeTerminalTextColor(WHITE);
    std::cout << "." << endl;
}

void showGameTitle() {
    TerminalUtils::changeTerminalTextColor(WHITE);
    std::cout << "WELCOME TO ";
    // Game title as red
    TerminalUtils::changeTerminalTextColor(BLUE);
    std::cout << "SUPER GAME SAGA";
    // Returning terminal color as white again
    TerminalUtils::changeTerminalTextColor(WHITE);
    std::cout << "!" << endl;
}

void GameMessage::showWelcomeMessage() {
    showGameTitle();
    cout << endl << "Press [TAB] to see game description.";
    GameMessage::showPressAnyKeyToContinueMessage();
}

void GameMessage::askForChangePlayerName() {
    // Asking for user input
    std::cout << endl << "Please, insert the ";
    TerminalUtils::changeTerminalTextColor(YELLOW);
    std::cout << "name you would want to be called";
    TerminalUtils::changeTerminalTextColor(WHITE);
    std::cout << " for: ";

    // User input, set terminal color to purple for enfatize
    // its name
    string userInput;
    TerminalUtils::changeTerminalTextColor(MAGENTA);
    std::cin >> userInput;

    // Set terminal color to white again and its name on character
    TerminalUtils::changeTerminalTextColor(WHITE);
    mainPlayer.setPlayerName(userInput);
}

void writeTextPressAnyKeyToContinue() {
    TerminalUtils::changeTerminalTextColor(YELLOW);
    cout << endl << ">> Press any key to continue... <<";
    TerminalUtils::changeTerminalTextColor(WHITE);
}

void showMenuPressAnyKeyToContinueMessageForMenu()  {
    writeTextPressAnyKeyToContinue();
    int pressedKey = _getch();
    if (pressedKey == 9) { // Tab key is pressed
        showGameDescription();
    }
}

void GameMessage::showPressAnyKeyToContinueMessage() {
    writeTextPressAnyKeyToContinue();
    _getch(); // Waits for a keypress without requiring Enter
}

void GameMessage::showInvalidInputTimerMessage(){
    int selectedSeconds = 3;
    // Start the timer thread
    thread timer(&TerminalUtils::timerThread, ref(timerExpired), selectedSeconds);

    // Update and display the message every second until timer expiration or user interrupt
    for (int seconds = selectedSeconds; seconds >= 0; --seconds) {
        // Sleep for 1 second
        this_thread::sleep_for(chrono::seconds(1));

        GameMessage::clearTerminalAndShowInvalidInputMessage();
        std::cout << endl << "Message disappearing in ";
        TerminalUtils::changeTerminalTextColor(YELLOW);
        std::cout << seconds;
        TerminalUtils::changeTerminalTextColor(WHITE);
        std::cout << " seconds.";
    }

    // Join the timer thread
    timer.join();

    TerminalUtils::clearTerminal();
    // Check the timer status
    if (timerExpired) std::cout << "Timer expired!" << endl;
}
