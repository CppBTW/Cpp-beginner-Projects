#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

// Function to safely take integer input
int getInput() {
    int x;
    while (true) {
        cin >> x;
        if (cin.fail()) {
            cout << "Invalid input. Enter a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            return x;
        }
    }
}

int main() {
    srand(time(0));
    char playAgain;

    do {
        int secretNumber = rand() % 100 + 1;
        int attempts = 0;
        int maxAttempts = 7;
        int score = 100;

        cout << "\n--- Number Guessing Game ---\n";
        cout << "Guess a number between 1 and 100\n";

        while (attempts < maxAttempts) {
            cout << "Attempt " << attempts + 1 << "/" << maxAttempts << ": ";
            int guess = getInput();

            if (guess < 1 || guess > 100) {
                cout << "Out of range! Try between 1–100.\n";
                continue;
            }

            attempts++;
            score -= 10;

            if (guess == secretNumber) {
                cout << "Correct! You guessed it in " << attempts << " attempts.\n";
                cout << "Score: " << score << "\n";
                break;
            }

            if (guess < secretNumber) {
                cout << "Too low! ";
            } else {
                cout << "Too high! ";
            }

            // Simple hint system
            int diff = abs(secretNumber - guess);
            if (diff <= 5)
                cout << "(Very close)\n";
            else if (diff <= 15)
                cout << "(Close)\n";
            else
                cout << "(Far)\n";
        }

        if (attempts == maxAttempts && secretNumber != 0) {
            cout << "You lost! Number was: " << secretNumber << "\n";
        }

        cout << "Play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}