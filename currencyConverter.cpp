#include <iostream>
using namespace std;

double CurrencyConverter(double amount, double from_rate, double to_rate)
{
    return amount * to_rate / from_rate;
}

int main()
{
    // Rates: units per USD
    double rates[] = {1.0, 83.0, 0.92, 0.78, 155.0, 1.5, 1.35};

    int from, to;
    double amount;

    cout << "=== Currency Converter ===\n";
    cout << "1. USD\n2. INR\n3. EUR\n4. GBP\n5. JPY\n6. AUD\n7. CAD\n";

    cout << "Select FROM currency: ";
    cin >> from;

    cout << "Enter amount: ";
    cin >> amount;

    cout << "Select TO currency: ";
    cin >> to;

    // Validation
    if (from < 1 || from > 7 || to < 1 || to > 7 || amount < 0)
    {
        cout << "Invalid input\n";
        return 0;
    }

    double result = CurrencyConverter(amount, rates[from - 1], rates[to - 1]);

    cout << amount << " converts to " << result << endl;

    return 0;
}