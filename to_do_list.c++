#include<iostream>
#include<fstream>
#include<string>
void InputTask()
{
    std::ofstream outFile("ToDoList.txt", std::ios::app);

    if (!outFile.is_open())
    {
        std::cerr << "Error opening file!\n";
        return;
    }

    std::string task;

    std::cin.ignore();

    std::cout << "Enter task: ";
    std::getline(std::cin, task);

    outFile << task << std::endl;

    outFile.close();

    std::cout << "Task added successfully.\n";
}

void viewTasks()
{
    std::ifstream inFile("ToDoList.txt",std::ios::app);

    if (!inFile.is_open()) {
        std::cerr << "Error opening file!\n";
        return;
    }

    std::string line;
    int count = 1;

    while (std::getline(inFile, line))
    {
        std::cout << count << ". " << line << std::endl;
        count++;
    }
}
void Delete_Tasks()
{
    std::ifstream inFile("ToDoList.txt",std::ios::app);

    if (!inFile.is_open()) {
        std::cerr << "Error opening file!\n";
        return;
    }

    int deleteLine;
    std::cout << "Enter task number to delete: ";
    std::cin >> deleteLine;

    std::ofstream tempFile("temp.txt");

    std::string line;
    int currentLine = 1;

    while (std::getline(inFile, line))
    {
        if (currentLine != deleteLine)
        {
            tempFile << line << std::endl;
        }

        currentLine++;
    }

    inFile.close();
    tempFile.close();

    remove("ToDoList.txt");
    rename("temp.txt", "ToDoList.txt");

    std::cout << "Task deleted successfully.\n";
}
int main()
{
    /*
    design a menu

    write task 
    view task
    delete task

    use fstream for storing and displaying data

    */
   int choice;

    do
    {
        std::cout << "\n===== TO DO LIST =====\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Delete Task\n";
        std::cout << "4. Exit\n";

        std::cout << "Enter choice: ";
        std::cin >> choice;

       if (choice == 1)
{
    InputTask();
}
else if (choice == 2)
{
    viewTasks();
}
else if (choice == 3)
{
    Delete_Tasks();
}
    }
    while (choice != 4);


}