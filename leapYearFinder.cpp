
#include <iostream>   // Needed for cin and cout (input/output)
using namespace std;  // Lets us write "cout" instead of "std::cout"

// -----------------------------------------------
// Function to check if a year is a leap year
// Returns true if it IS a leap year, false if not
// -----------------------------------------------
bool isLeapYear(int year) {

    // Rule: Divisible by 400 → always a leap year
    if (year % 400 == 0) {
        return true;
    }

    // Rule: Divisible by 100 (but NOT 400) → NOT a leap year
    if (year % 100 == 0) {
        return false;
    }

    // Rule: Divisible by 4 → leap year
    if (year % 4 == 0) {
        return true;
    }

    // Everything else → NOT a leap year
    return false;
}

// -----------------------------------------------
// Main function — this is where the program starts
// -----------------------------------------------
int main() {

    int year;  // Variable to store the year entered by the user

    cout << "==============================" << endl;
    cout << "      LEAP YEAR FINDER        " << endl;
    cout << "==============================" << endl;
    cout << endl;


    cout << "Enter a year: ";
    cin >> year;


    if (year <= 0) {
        cout << "Please enter a valid positive year!" << endl;
        return 1;  // Exit with an error code
    }

        if (isLeapYear(year)) {
        cout << endl;
        cout << year << " IS a leap year! 🗓️" << endl;
        cout << "It has 366 days." << endl;
    } else {
        cout << endl;
        cout << year << " is NOT a leap year." << endl;
        cout << "It has 365 days." << endl;
    }

    cout << endl;
    return 0;  // 0 means the program ended successfully
}