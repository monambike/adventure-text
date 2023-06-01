#include <iostream>
using namespace std;

class Player{
    public:
        int life = 100; // If life reaches 0, then it's game over, life cannot be under 0
        string name = "Player Name"; // User can change player name
   
    void changePlayerName(string newName){
        name = newName;
        cout << "You have successfully changed your name for " << newName << "." << endl;
    }
};
Player mainPlayer;

class GameMessage {
    public:
        static void writeWelcomeMessage() {
            cout
            << "Welcome to [game-name]!" << endl
            << endl
            << "Please, insert the name you would want to be called for: ";

            string userInput;
            cin >> userInput;
            mainPlayer.changePlayerName(userInput);
        }
};

int main() {
    GameMessage::writeWelcomeMessage();
    return 0;
}
