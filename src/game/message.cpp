// Copyright(c) 2023-present, Vinícius Gabriel (@monambike)
// Distributed under Creative Commons License (https://creativecommons.org/licenses/by/4.0/)

#include <chrono>
#include <conio.h>
#include <iostream>
#include <thread>
#include "message.hpp"
#include "../entities/player.hpp"
#include "../utilities/terminal_utils.hpp"

const int TAB_KEY = 9;
const int ESC_KEY = 27;
const int ENTER_KEY = 13;

enum GameFlow {
    GO_TO_TITLE_SCREEN,
    GO_TO_GAME_DESCRIPTION,
    RUN_GAME,
    EXIT_GAME
};

#pragma region Private

void showPressAnyKeyToContinueText() {
    TerminalUtils::changeTerminalTextColor(YELLOW);
    cout << endl << ">> Press any key to continue... <<";
    TerminalUtils::changeTerminalTextColor(WHITE);
}

void showGameTitleText() {
    TerminalUtils::changeTerminalTextColor(WHITE);
    std::cout << "WELCOME TO ";
    // Game title as red
    TerminalUtils::changeTerminalTextColor(BLUE);
    std::cout << "SUPER GAME SAGA";
    // Returning terminal color as white again
    TerminalUtils::changeTerminalTextColor(WHITE);
    std::cout << "!" << endl;

    TerminalUtils::changeTerminalTextColor(YELLOW);
    cout << "Press [TAB] key to show game description." << endl;
    cout << "Press [ESC] to exit.";
    TerminalUtils::changeTerminalTextColor(WHITE);

    showPressAnyKeyToContinueText();
}

GameFlow processInputAndGetGameFlow(int keyPress) {
    switch (keyPress) {
        case TAB_KEY:
            if (1 == 1) { // if already is on the title
                return GO_TO_GAME_DESCRIPTION;
            }
            return GO_TO_TITLE_SCREEN;
        case ESC_KEY: return EXIT_GAME;
        default: return RUN_GAME;
    }
}

void GameMessage::startGameHomeScreen() {
    showGameTitleText();
    while(true) {
        GameFlow gameFlow;
        while(true) {
            // Getting what user want to do next
            int keyPress = _getch();
            gameFlow = processInputAndGetGameFlow(keyPress);
        }

        TerminalUtils::clearTerminal();

        if (gameFlow == RUN_GAME) break;
        else if (gameFlow == EXIT_GAME) exit(0);

        if (gameFlow == GO_TO_TITLE_SCREEN) showGameTitleText();
        else if (gameFlow == GO_TO_GAME_DESCRIPTION) showGameDescriptionScreen();
    }
}

void GameMessage::showGameDescriptionText() {
    std::cout << R"(
In this game, you will embark on a captivating journey through many
adventures.
Your choices will shape the destiny of your character and the outcome
of the game.

This is a small game created to learn and explore the essentials of C++
and the powerful capabilities it provides.

Enjoy the adventure and let the history unfold!
    )";
}

void GameMessage::showGameDescriptionScreen() {
    TerminalUtils::clearTerminal();
    GameMessage::showGameDescriptionText();
    TerminalUtils::changeTerminalTextColor(YELLOW);
    cout << "Press [TAB] key to return for menu." << endl;
    cout << "Press [ESC] to exit.";
    TerminalUtils::changeTerminalTextColor(WHITE);
}

void GameMessage::showMenuPressAnyKeyToContinueMessageForWelcomeMessage()  {
    showPressAnyKeyToContinueText();
    int pressedKey = _getch();
    const int TAB_KEY = 9;
    if (pressedKey == TAB_KEY) { // Tab key is pressed
        showGameDescriptionScreen();
    }
}

#pragma endregion

#pragma region Public

void GameMessage::showWelcomeMessageAndWaitKeyPress() {
    startGameHomeScreen();

    // startGameHomeScreen();
    // cout << endl << "Press [TAB] to see game description.";
    // GameMessage::showMenuPressAnyKeyToContinueMessageForWelcomeMessage();
}

void GameMessage::askForPlayerNameChange() {
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

void GameMessage::showPressAnyKeyToContinueMessage() {
    showPressAnyKeyToContinueText();
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

void GameMessage::clearTerminalAndShowInvalidInputMessage() {
    TerminalUtils::clearTerminal();
    TerminalUtils::changeTerminalTextColor(RED);
    std::cout << "INVALID INPUT" << endl << endl;;
    TerminalUtils::changeTerminalTextColor(WHITE);
    std::cout << "This option it's not a valid input, please select an option from ";
    TerminalUtils::changeTerminalTextColor(RED);
    std::cout << "list of actions";
    TerminalUtils::changeTerminalTextColor(WHITE);
    std::cout << "." << endl;
}

#pragma endregion
