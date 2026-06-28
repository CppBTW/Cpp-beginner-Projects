/*

```
==================================================
            PERSONAL EXPENSE TRACKER
==================================================

Description:
Personal Expense Tracker is a console-based C++
project that helps users record and manage their
daily expenses. The program stores expense records
in text files and provides tools to view, search,
edit, delete, and analyze spending data.

--------------------------------------------------

Author      : cpp_btw
Version     : 1.0
Language    : C++
File System : Text Files (fstream)

--------------------------------------------------

Note:

This project was created as a learning exercise to
improve my C++ programming and file handling skills.
As I am still learning, feedback and suggestions are
always welcome.

Discord: cpp_btw

Thank you for checking out this project! 😁

==================================================
                    FEATURES
==================================================

1. Add Expenses
   - Store expense details in "expenses.txt".
   - Save information such as expense name,
     category, amount, and date.

     28/06/2026   ✅ should pass
     01/01/2025   ✅ should pass
     31/12/2100   ✅ should pass

     1/1/2026     ❌ should fail
     28-06-2026   ❌ should fail
     32/01/2026   ❌ should fail
     15/13/2026   ❌ should fail

2. View Expense History
   - Display all stored expenses in an organized
     format.
   - Review previous spending records easily.

3. Search Expenses
   - Search records using keywords, names,
     or categories.
   - Quickly locate specific expenses.



4. Delete Expense Records
   - Remove unwanted expense entries.
   - Prevents file corruption during deletion.


~ File-Based Data Storage
   - Records remain saved even after the program
     is closed.
   - Uses C++ file handling (fstream).

~ Beginner-Friendly Interface
   - Simple menu-driven design.
   - Easy to navigate and understand.

==================================================
            TEMPORARY FILE TECHNIQUE
==================================================

The Temporary File Technique is a safe method for
updating records stored in text files.

Why use it?

- Text files are sequential.
- Data cannot be easily inserted or removed from
  the middle of a file.
- Direct modification may corrupt data if the
  program crashes during an update.

How it works:

1. Open the original file for reading.
2. Open a temporary file for writing.
3. Copy records one by one.
4. Modify, skip, or add records as needed.
5. Close both files.
6. Delete the original file.
7. Rename the temporary file.

This technique is commonly used in:

- Library Management Systems
- Student Record Systems
- Inventory Management Systems
- Expense Tracking Applications

==================================================
              FUTURE IMPROVEMENTS
==================================================

- Monthly Expense Reports
- Budget Planning System
- Expense Categories Statistics
- Password Protection
- CSV Export Support

==================================================
```

Current Status : In Development
*/

#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <windows.h>

void AddExpenses();
void display();
void SearchExpenses();
void deleteExpense();

bool validDate(const std::string &date);

struct Expenses
{
    std::string name;
    std::string category;
    double amount;
    std::string date;
};
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    while (true)
    {
        std::string choice;

        std::cout << "=====================================\n";
        std::cout << "||     PERSONAL EXPENSE TRACKER    ||\n";
        std::cout << "=====================================\n";

        std::cout << "(A)dd Expenses\n";
        std::cout << "(V)iew\n";
        std::cout << "(SE)arch Expenses\n";

        std::cout << "(D)elete existing expenses\n";

        std::cout << "(E)xit\n";

        std::getline(std::cin, choice);

        for (char &c : choice)
        {
            c = toupper(c);
        }

        if (choice == "A")
        {
            AddExpenses();
        }
        else if (choice == "V")
        {
            display();
        }
        else if (choice == "SE")
        {
            SearchExpenses();
        }

        else if (choice == "D")
        {
            deleteExpense();
        }

        else if (choice == "E")
        {
            std::cout << "Have a nice day\n";
            break;
        }
        else
        {
            std::cout << "Invalid choice!\n";
        }
    }
    return 0;
}

void AddExpenses()
{
    
    /*
--------------------------------------------------
Date Validation Function

This function checks whether the entered date
follows the required format: DD/MM/YYYY.

Validation performed:
- Date must contain exactly 10 characters.
- '/' must appear at positions 3 and 6.
- All other characters must be digits.
- Day must be between 1 and 31.
- Month must be between 1 and 12.
- Year must be between 2000 and 2100.

Returns:
- true  -> if the date format is valid.
- false -> if the date format is invalid.

Note:
This function validates the basic date format only.
It does not verify whether a calendar date actually
exists (for example, 31/02/2026 is accepted).
--------------------------------------------------
*/

    int choice;
    Expenses e;

    std::cout << "Enter the name of expense\n";
    std::getline(std::cin, e.name);

    std::cout << "Enter the date (DD/MM/YYYY):\n";
    std::getline(std::cin, e.date);

    if (!validDate(e.date))
    {
        std::cout << "Invalid date!\n";
        return;
    }
    std::cout << "Enter amount \n";
    std::cin >> e.amount;
    std::cin.ignore();

    if (e.amount < 0)
    {

        std::cout << "Amount cannot be negative.\n";
        return;
    };
    std::cout << "\nSelect Category\n";
    std::cout << "1. Food\n";
    std::cout << "2. Transport\n";
    std::cout << "3. Shopping\n";
    std::cout << "4. Entertainment\n";
    std::cout << "5. Bills\n";
    std::cout << "6. Health\n";
    std::cout << "7. Education\n";
    std::cout << "Choice: ";

    std::cin >> choice;
    std::cin.ignore();

    switch (choice)
    {
    case 1:
        e.category = "Food";
        break;
    case 2:
        e.category = "Transport";
        break;
    case 3:
        e.category = "Shopping";
        break;
    case 4:
        e.category = "Entertainment";
        break;
    case 5:
        e.category = "Bills";
        break;
    case 6:
        e.category = "Health";
        break;
    case 7:
        e.category = "Education";
        break;
    default:
        e.category = "Other";
    }

    std::ofstream out("expenses.txt", std::ios::app);

    if (!out)
    {
        std::cout << "Unable to open a file\n";
        return;
    }

    out << e.name << "|"
        << e.date << "|"
        << e.amount << "|"
        << e.category << "\n";

    out.close();

    std::cout << "\nExpense added successfully!\n";
};

void display()
{
    std::ifstream InFile("expenses.txt");
    int serial = 1;
    if (!InFile)
    {
        std::cout << "Could not open file" << std::endl;
        return;
    }
    if (InFile.peek() == std::ifstream::traits_type::eof())
    {
        std::cout << "There are no expenses added" << std::endl;
        return;
    }
    std::string line;

    std::cout << std::left
              << std::setw(5) << "No"
              << std::setw(25) << "Name"
              << std::setw(15) << "Date"
              << std::setw(15) << "Amount"
              << std::setw(20) << "Category"
              << '\n';

    std::cout << "----------------------------------------------------------------------------------" << std::endl;

    while (getline(InFile, line))
    {
        std::stringstream ss(line);

        std::string name;
        std::string date;
        std::string amount;
        std::string category;

        std::getline(ss, name, '|');
        std::getline(ss, date, '|');
        std::getline(ss, amount, '|');
        std::getline(ss, category, '|');

        std::cout << std::setw(5) << serial++
                  << std::setw(25) << name
                  << std::setw(15) << date
                  << "₹" << std::setw(14) << amount
                  << std::setw(20) << category
                  << std::endl;
    }
    std::cout << std::endl;

    InFile.close();
};

bool validDate(const std::string &date)
{
    if (date.length() != 10)
        return false;

    if (date[2] != '/' || date[5] != '/')
        return false;

    for (int i = 0; i < date.length(); i++)
    {
        if (i == 2 || i == 5)
            continue;

        if (!isdigit(date[i]))
            return false;
    }

    int day = std::stoi(date.substr(0, 2));
    int month = std::stoi(date.substr(3, 2));
    int year = std::stoi(date.substr(6, 4));

    if (day < 1 || day > 31)
        return false;

    if (month < 1 || month > 12)
        return false;

    if (year < 2000 || year > 2100)
        return false;

    return true;
}
void SearchExpenses()
{
    int SearchNumber;

    std::cout << "\nEnter the serial number of the expense to see: ";
    std::cin >> SearchNumber;
    std::cin.ignore();

    std::ifstream InFile("expenses.txt");

    if (!InFile)
    {
        std::cout << "Error opening file.\n";
        return;
    }

    std::string line;
    bool found = false;
    int currentNo = 1;

    while (getline(InFile, line))
    {
        std::stringstream ss(line);

        std::string name, date, amount, category;

        getline(ss, name, '|');
        getline(ss, date, '|');
        getline(ss, amount, '|');
        getline(ss, category, '|');

        if (currentNo == SearchNumber)
        {
            found = true;

            std::cout << "\nExpense Found\n";
            std::cout << "Name     : " << name << '\n';
            std::cout << "Date     : " << date << '\n';
            std::cout << "Amount   : ₹" << amount << '\n';
            std::cout << "Category : " << category << '\n';

            break;
        }

        currentNo++;
    }

    if (!found)
    {
        std::cout << "Invalid serial number.\n";
    }

    InFile.close();
}

void deleteExpense()
{
    display(); // Show all expenses first

    int deleteNo;
    std::cout << "\nEnter the serial number of the expense to delete: ";
    std::cin >> deleteNo;
    std::cin.ignore();

    std::ifstream InFile("expenses.txt");
    std::ofstream TempFile("TempFile.txt");

    if (!InFile || !TempFile)
    {
        std::cout << "Error opening file.\n";
        return;
    }

    std::string line;
    bool found = false;
    int currentNo = 1;

    while (getline(InFile, line))
    {
        std::stringstream ss(line);

        std::string name, date, amount, category;

        getline(ss, name, '|');
        getline(ss, date, '|');
        getline(ss, amount, '|');
        getline(ss, category, '|');

        if (currentNo == deleteNo)
        {
            found = true;
            currentNo++;
            continue; // Skip this record
        }

        TempFile << name << "|"
                 << date << "|"
                 << amount << "|"
                 << category << "\n";

        currentNo++;
    }

    InFile.close();
    TempFile.close();

    if (found)
    {
        remove("expenses.txt");
        rename("TempFile.txt", "expenses.txt");
        std::cout << "\nExpense deleted successfully!\n";
    }
    else
    {
        remove("TempFile.txt");
        std::cout << "\nInvalid serial number.\n";
    }
}
