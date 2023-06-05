#include <chrono>
#include <conio.h>
#include <iostream>
#include <thread>
#include "GameMessage.h"
#include "Player.h"
#include "TerminalUtils.h"

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

void GameMessage::ClearTerminalAndShowInvalidInputMessage() {
    TerminalUtils::ClearTerminal();
    TerminalUtils::ChangeTerminalTextColor(Red);
    std::cout << "INVALID INPUT" << endl << endl;;
    TerminalUtils::ChangeTerminalTextColor(WHITE);
    std::cout << "This option it's not a valid input, please select an option from ";
    TerminalUtils::ChangeTerminalTextColor(Red);
    std::cout << "list of actions";
    TerminalUtils::ChangeTerminalTextColor(WHITE);
    std::cout << "." << endl;
}

void ShowGameTitle() {
    TerminalUtils::ChangeTerminalTextColor(WHITE);
    std::cout << "WELCOME TO ";
    // Game title as red
    TerminalUtils::ChangeTerminalTextColor(BLUE);
    std::cout << "SUPER GAME SAGA";
    // Returning terminal color as white again
    TerminalUtils::ChangeTerminalTextColor(WHITE);
    std::cout << "!" << endl;
}

void GameMessage::showWelcomeMessage() {
    ShowGameTitle();
    cout << endl << "Press [TAB] to see game description.";
    GameMessage::ShowPressAnyKeyToContinueMessage();
}

void GameMessage::AskForChangePlayerName() {
    // Asking for user input
    std::cout << endl << "Please, insert the ";
    TerminalUtils::ChangeTerminalTextColor(YELLOW);
    std::cout << "name you would want to be called";
    TerminalUtils::ChangeTerminalTextColor(WHITE);
    std::cout << " for: ";

    // User input, set terminal color to purple for enfatize
    // its name
    string userInput;
    TerminalUtils::ChangeTerminalTextColor(MAGENTA);
    std::cin >> userInput;

    // Set terminal color to white again and its name on character
    TerminalUtils::ChangeTerminalTextColor(WHITE);
    mainPlayer.SetPlayerName(userInput);
}

void writeTextPressAnyKeyToContinue() {
    TerminalUtils::ChangeTerminalTextColor(YELLOW);
    cout << endl << ">> Press any key to continue... <<";
    TerminalUtils::ChangeTerminalTextColor(WHITE);
}

void ShowMenuPressAnyKeyToContinueMessageForMenu()  {
    writeTextPressAnyKeyToContinue();
    int pressedKey = _getch();
    if (pressedKey == 9) { // Tab key is pressed
        showGameDescription();
    }
}

void GameMessage::ShowPressAnyKeyToContinueMessage() {
    writeTextPressAnyKeyToContinue();
    _getch(); // Waits for a keypress without requiring Enter
}

void GameMessage::ShowInvalidInputTimerMessage(){
    int selectedSeconds = 3;
    // Start the timer thread
    thread timer(&TerminalUtils::TimerThread, ref(timerExpired), selectedSeconds);

    // Update and display the message every second until timer expiration or user interrupt
    for (int seconds = selectedSeconds; seconds >= 0; --seconds) {
        // Sleep for 1 second
        this_thread::sleep_for(chrono::seconds(1));

        GameMessage::ClearTerminalAndShowInvalidInputMessage();
        std::cout << endl << "Message disappearing in ";
        TerminalUtils::ChangeTerminalTextColor(YELLOW);
        std::cout << seconds;
        TerminalUtils::ChangeTerminalTextColor(WHITE);
        std::cout << " seconds.";
    }

    // Join the timer thread
    timer.join();

    TerminalUtils::ClearTerminal();
    // Check the timer status
    if (timerExpired) std::cout << "Timer expired!" << endl;
}
