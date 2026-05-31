
/*

1. Add Book
2. Display Books
3. Issue Book
4. Return Book
5.Exit

 1) ADD~

make a file add books with publicsher id, title, quantity and author .
Use append in file method to make it look arranged

Example -
        id     Author           title
   1)   101    J.K Rowlingsa    Harry Potter philosopher's stone
   2)   102    Sudha Murty      Dollar Bahu


   2) Display book~

     read out the file in an sysrtematic way with serial numbers.

   3)Issue book~

    1. Take book ID from user
    2. Open original + temp file
    3. Read each book
    4. Check matching ID
    5. Check availability
    6. Write updated record into temp file
    7. Close files and replace original

   4) return book~
      if returnBook() func use then we will just simply add +1 for every time the function is called

   5) exit~
      break out of the loop and display "have a nice day "
   */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// This is cleaner and safer.

void addBook();
void displayBooks();
void issueBooks();
void returnBooks();
void deleteBook();

struct Book
{

    int id;
    string name;
    string author;
    int quantity;
};

int main()
{
    int userRequest;

    cout << "~Welcome to the Library~" << endl;

    cout << "\n";
    while (true)
    {

        cout << " 1) Add book\n\n 2) Display books\n\n 3) issue books.\n\n 4) return book\n\n 5) delete book\n\n 6) Exit \n\n"
             << endl;

        cin >> userRequest;

        switch (userRequest)
        {
        case 1:

            addBook();

            break;
        case 2:

            displayBooks();

            break;

        case 3:
            issueBooks();

            break;
        case 4:
            returnBooks();
            break;
        case 5:
            deleteBook();
            break;
        case 6:
           cout << "Have a nice day" << endl;
            return 0;

        default:
            cout << "Invalid option" << endl;

            break;
        }
    }
    return 0;
}

void addBook()
{
   Book b;

cout << "Enter Book ID" << endl;
cin >> b.id;

std::ifstream CheckFile("Books.txt");

if(CheckFile)
{
    string line;

    while(getline(CheckFile, line))
    {if(line.empty())
    {
        continue;
    }
        if(line.empty())
    {
        continue;
    }
        std::stringstream ss(line);

        string idStr;
        getline(ss, idStr, '|');

        int existingID = std::stoi(idStr);

        if(existingID == b.id)
        {
              CheckFile.close();
            cout << "Book ID already exists" << endl;
            return;
        }
    }

    CheckFile.close();
}

std::ofstream OutFile("Books.txt", std::ios::app);

if(!OutFile)
{
    cout << "Could not open file" << endl;
    return;
}

    cin.ignore(1000, '\n');

    cout << "Enter authors name" << endl;

    std::getline(cin, b.author);

    cout << "enter book title" << endl;

    std::getline(cin, b.name);

    cout << " enter book quantity " << endl;

    cin >> b.quantity;

    cin.ignore(1000, '\n');

    OutFile << b.id << "|"
            << b.name << "|"
            << b.author << "|"
            << b.quantity << "\n";
            
            cout << "Book added successfully" << endl;
    OutFile.close();
}
void displayBooks()
{
    std::ifstream InFile("Books.txt");
    int serial = 1;
    if (!InFile)
    {
        cout << "Could not open file" << endl;
        return;
    }
    if (InFile.peek() == std::ifstream::traits_type::eof())
    {
        cout << "There are no books in the library" << endl;
        return;
    }
    string line;

    cout << std::left
         << std::setw(5) << "No."
         << std::setw(10) << "ID"
         << std::setw(30) << "Title"
         << std::setw(25) << "Author"
         << std::setw(10) << "Quantity"
         << endl;

    cout << "----------------------------------------------------------------------------------" << endl;

    while (getline(InFile, line))
    {
        std::stringstream ss(line);

        string id;
        string title;
        string author;
        string quantity;

        getline(ss, id, '|');
        getline(ss, title, '|');
        getline(ss, author, '|');
        getline(ss, quantity, '|');

        cout << std::setw(5) << serial++
             << std::setw(10) << id
             << std::setw(30) << title
             << std::setw(25) << author
             << std::setw(10) << quantity
             << endl;
    }
    cout << endl;

    InFile.close();
}

void issueBooks()
{

    int IdSearch;

    std::ifstream InFile("Books.txt");
    std::ofstream TempFile("TempFile.txt");
    if (!InFile || !TempFile)
    {
        cout << "Error opening File" << endl;
        return;
    }

    cout << "Enter book Id u want to issue" << endl;
    cin >> IdSearch;

    std::string line;
    bool found = false;

    while (getline(InFile, line))
    {
        std::stringstream ss(line);

        string idstr, title, author, strquantity;

        getline(ss, idstr, '|');
        getline(ss, title, '|');
        getline(ss, author, '|');
        getline(ss, strquantity, '|');

        int id = std::stoi(idstr);
        int quantity = std::stoi(strquantity);

        if (IdSearch == id)
        {
            found = true;

            if (quantity > 0)
            {
                cout << "Book successfully issued" << endl;
                quantity--;
            }
            else
            {
                cout << "Book not available" << endl;
            }
        }
        TempFile << id << "|"
                 << title << "|"
                 << author << "|"
                 << quantity << "\n";
    }
    if (!found)
    {
        cout << "Book ID Not found " << endl;
    }

    InFile.close();
    TempFile.close();

    if (remove("Books.txt") != 0)
    {
        cout << "Error deleting old file" << endl;
    }

    if (rename("TempFile.txt", "Books.txt") != 0)
    {
        cout << "Error renaming file" << endl;
    }
}

void returnBooks()
{

    int IdSearch;

    std::ifstream InFile("Books.txt");
    std::ofstream TempFile("TempFile.txt");
    if (!InFile || !TempFile)
    {
        cout << "Error opening File" << endl;
        return;
    }

    cout << "Enter book Id u want to return" << endl;
    cin >> IdSearch;

    std::string line;
    bool found = false;

    while (getline(InFile, line))
    {
        std::stringstream ss(line);

        string idstr, title, author, strquantity;

        getline(ss, idstr, '|');
        getline(ss, title, '|');
        getline(ss, author, '|');
        getline(ss, strquantity, '|');

        int id = std::stoi(idstr);
        int quantity = std::stoi(strquantity);

        if (IdSearch == id)
        {
            found = true;

            cout << "Book successfully returned" << endl;
            quantity++;
        }

        TempFile << id << "|"
                 << title << "|"
                 << author << "|"
                 << quantity << "\n";
    }
    if (!found)
    {
        cout << "Book ID Not found " << endl;
    }

    InFile.close();
    TempFile.close();

    if (remove("Books.txt") != 0)
    {
        cout << "Error deleting old file" << endl;
    }

    if (rename("TempFile.txt", "Books.txt") != 0)
    {
        cout << "Error renaming file" << endl;
    }
}

void deleteBook()
{
    int IdSearch;

    std::ifstream InFile("Books.txt");
    std::ofstream TempFile("TempFile.txt");

    if (!InFile || !TempFile)
    {
        cout << "Error opening file" << endl;
        return;
    }

    cout << "Enter book ID you want to delete" << endl;
    cin >> IdSearch;

    string line;
    bool found = false;

    while (getline(InFile, line))
    {
        std::stringstream ss(line);
        string idstr, title, author, strquantity;

        getline(ss, idstr,       '|');
        getline(ss, title,       '|');
        getline(ss, author,      '|');
        getline(ss, strquantity, '|');

        int id = std::stoi(idstr);

        if (id == IdSearch)
        {
            found = true;
            // Simply skip writing this record → it gets deleted
            cout << "Book \"" << title << "\" deleted successfully" << endl;
            continue;
        }

        // Write every OTHER record back to the temp file
        TempFile << idstr << "|" << title << "|" << author << "|" << strquantity << "\n";
    }

    if (!found)
        cout << "Book ID not found" << endl;

    InFile.close();
    TempFile.close();

    if (remove("Books.txt") != 0)
        cout << "Error deleting old file" << endl;
    if (rename("TempFile.txt", "Books.txt") != 0)
        cout << "Error renaming file" << endl;
}