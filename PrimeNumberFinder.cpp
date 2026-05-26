

#include <iostream>
using namespace std;

int main()
{

    int number;

    cout << "Enter a number: ";
    cin >> number;

    // Numbers less than 2 are not prime
    if (number < 2)
    {
        cout << number << " is NOT a prime number." << endl;
        return 0;
    }

    // Try dividing by every number from 2 to number-1
    bool isPrime = true;

    for (int i = 2; i < number; i++)
    {
        if (number % i == 0)
        { // If it divides evenly, not prime
            isPrime = false;
            break; // No need to check further
        }
    }
    
    // Show the result
    if (isPrime)
    {
        cout << number << " IS a prime number!" << endl;
    }
    else
    {
        cout << number << " is NOT a prime number." << std::endl;
    }

    return 0;
}
