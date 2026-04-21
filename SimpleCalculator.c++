#include <iostream>
using namespace std;

int add(int num1, int num2) {
    return num1 + num2;
}

int subtraction(int num1, int num2) {
    return num1 - num2;
}

int multiplication(int num1, int num2) {
    return num1 * num2;
}

int division(int num1, int num2) {
    return num1 / num2;
}

int main() {
    int operation;
    int num1, num2;

    cout << "---- Calculator ----" << endl;

    while (true) {
        cout << "\nEnter 1: Addition\n";
        cout << "Enter 2: Subtraction\n";
        cout << "Enter 3: Multiplication\n";
        cout << "Enter 4: Division\n";
        cout << "Enter 5: Exit\n";
        cout << "Choose operation: ";

        cin >> operation;

        switch (operation) {
        case 1:
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
            cout << "Sum: " << add(num1, num2) << endl;
            break;

        case 2:
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
            cout << "Difference: " << subtraction(num1, num2) << endl;
            break;

        case 3:
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
            cout << "Product: " << multiplication(num1, num2) << endl;
            break;

        case 4:
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;

            if (num2 == 0) {
                cout << "Error: Cannot divide by zero!" << endl;
            } else {
                cout << "Quotient: " << division(num1, num2) << endl;
            }
            break;

        case 5:
            cout << "Thank you, visit again!" << endl;
            return 0;

        default:
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}