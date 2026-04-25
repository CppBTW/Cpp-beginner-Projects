#include <iostream>
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()

using namespace std;

int main() {
    srand(time(0)); // seed random number generator

    int userChoice;
    int computerChoice;

    cout << "=== Rock Paper Scissors ===\n";
    cout << "1. Rock\n2. Paper\n3. Scissors\n";

    cout << "Enter your choice (1-3): ";
    cin >> userChoice;

    // Generate computer choice (1 to 3)
    computerChoice = rand() % 3 + 1;

    cout << "Computer chose: ";

    if (computerChoice == 1)
        cout << "Rock\n";
    else if (computerChoice == 2)
        cout << "Paper\n";
    else
        cout << "Scissors\n";

    // Display user's choice
    cout << "You chose: ";
    if (userChoice == 1)
        cout << "Rock\n";
    else if (userChoice == 2)
        cout << "Paper\n";
    else if (userChoice == 3)
        cout << "Scissors\n";
    else {
        cout << "Invalid input\n";
        return 0;
    }

    // Game logic
    if (userChoice == computerChoice) {
        cout << "It's a draw!\n";
    }
    else if ((userChoice == 1 && computerChoice == 3) ||
             (userChoice == 2 && computerChoice == 1) ||
             (userChoice == 3 && computerChoice == 2)) {
        cout << "You win!\n";
    }
    else {
        cout << "You lose!\n";
    }

    return 0;
}