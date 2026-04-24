#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    string name;
    int age;
    int choice;

    while(true)
    {
        cout << "\n1. Add Data\n2. View Data\n3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore(); //removes one character from the buffer (usually the leftover \n)

        if(choice == 1)
        {
            ofstream file("data.txt", ios::app);

            cout << "Enter your name: ";
            getline(cin, name);

            cout << "Enter your age: ";
            cin >> age;
            cin.ignore();

            file << "Name: " << name << endl;
            file << "Age: " << age << endl;
            file << "------------------" << endl;

            file.close();
        }

        else if(choice == 2)
        {
            ifstream read("data.txt");
            string line;

            while(getline(read, line))
            {
                cout << line << endl;
            }

            read.close();
        }

        else if(choice == 3)
        {
            break;
        }

        else
        {
            cout << "Invalid choice\n";
        }
    }

    return 0;
}