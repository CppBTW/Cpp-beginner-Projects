#include <iostream>

int main()
{
    const int CURRENT_YEAR = 2026;

    int birthYear;

    std::cout << "Enter your birth year: ";
    std::cin >> birthYear;

    if (birthYear > CURRENT_YEAR)
    {
        std::cout << "Invalid birth year\n";
        return 1;
    }

    int age = CURRENT_YEAR - birthYear;

    std::cout << "You are " << age << " years old.\n";

    return 0;
}