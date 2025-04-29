#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    char playAgain;

    do {
        int numberToGuess = rand() % 100 + 1;
        int userGuess;
        int attempts = 0;

        cout << "\n=== Number Guessing Game ===" << endl;
        cout << "Guess a number between 1 and 100." << endl;

        do {
            cout << "Enter your guess: ";
            cin >> userGuess;
            attempts++;

            if (userGuess > numberToGuess) {
                cout << "Too high! Try again." << endl;
            } else if (userGuess < numberToGuess) {
                cout << "Too low! Try again." << endl;
            } else {
                cout << "Congratulations! You guessed the number in " << attempts << " attempts." << endl;
            }
        } while (userGuess != numberToGuess);

        cout << "Do you want to play again? (Y/N): ";
        cin >> playAgain;

    } while (playAgain == 'Y' || playAgain == 'y');

    cout << "Thank you for playing!" << endl;
    return 0;
}
