#include <iostream>
#include <conio.h>
#include <chrono>
#include <thread>
#include "GameMessage.h"
#include "Player.h"
#include "TerminalUtils.h"
using namespace std;

void GameMessage::ClearTerminalAndShowInvalidInputMessage() {
    TerminalUtils::ClearTerminal();
    TerminalUtils::ChangeTerminalTextColor(Red);
    cout << "INVALID INPUT" << endl << endl;;
    TerminalUtils::ChangeTerminalTextColor(WHITE);
    cout << "This option it's not a valid input, please select an option from ";
    TerminalUtils::ChangeTerminalTextColor(Red);
    cout << "list of actions";
    TerminalUtils::ChangeTerminalTextColor(WHITE);
    cout << "." << endl;
}

void GameMessage::ShowWelcomeMessage() {
    TerminalUtils::ChangeTerminalTextColor(WHITE);
    cout << "WELCOME TO ";
    // Game title as red
    TerminalUtils::ChangeTerminalTextColor(BLUE);
    cout << "SUPER GAME SAGA" << endl
         << "           SUPER GAME SAGA" << endl
         << "           SUPER GAME SAGA";
    // Returning terminal color as white again
    TerminalUtils::ChangeTerminalTextColor(WHITE);
    cout << "!" << endl;

    cout << R"(
______________________________

In this game, you will embark on a captivating journey through many
adventures.
Your choices will shape the destiny of your character and the outcome
of the game.

This is a small game created to learn and explore the essentials of C++
and the powerful capabilities it provides.

Enjoy the adventure and let the history unfold!
______________________________
    )";

    GameMessage::ShowPressAnyKeyToContinueMessage();
}

void GameMessage::AskForChangePlayerName() {
    // Asking for user input
    cout << endl << "Please, insert the ";
    TerminalUtils::ChangeTerminalTextColor(YELLOW);
    cout << "name you would want to be called";
    TerminalUtils::ChangeTerminalTextColor(WHITE);
    cout << " for: ";

    // User input, set terminal color to purple for enfatize
    // its name
    string userInput;
    TerminalUtils::ChangeTerminalTextColor(MAGENTA);
    cin >> userInput;

    // Set terminal color to white again and its name on character
    TerminalUtils::ChangeTerminalTextColor(WHITE);
    mainPlayer.SetPlayerName(userInput);
}

void GameMessage::ShowPressAnyKeyToContinueMessage() {
    TerminalUtils::ChangeTerminalTextColor(YELLOW);
    cout << endl << ">> Press any key to continue... <<";
    TerminalUtils::ChangeTerminalTextColor(WHITE);
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
        cout << endl << "Message disappearing in ";
        TerminalUtils::ChangeTerminalTextColor(YELLOW);
        cout << seconds;
        TerminalUtils::ChangeTerminalTextColor(WHITE);
        cout << " seconds.";
    }

    // Join the timer thread
    timer.join();

    TerminalUtils::ClearTerminal();
    // Check the timer status
    if (timerExpired) cout << "Timer expired!" << endl;
}
