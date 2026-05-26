#include<iostream>
#include<vector>

double AverageMarks(std::vector<int>& marks)
{
    int sum = 0;

    for(int m : marks)
    {
        sum += m;
    }

    return (double)sum / marks.size();
}

char CalculateGrade(double average)
{
    if(average >= 90)
    {
        return 'A';
    }
    else if(average >= 80)
    {
        return 'B';
    }
    else if(average >= 70)
    {
        return 'C';
    }
    else if(average >= 60)
    {
        return 'D';
    }
    else
    {
        return 'F';
    }
}

int main()
{
    int NumberOfsubjects;

    std::cout << "~Welcome to Student Grading System~\n";

    std::cout << "Enter number of subjects: ";
    std::cin >> NumberOfsubjects;

    std::vector<int> subjects(NumberOfsubjects);

    for(int i = 0; i < NumberOfsubjects; i++)
    {
        std::cout << "Enter marks: ";
        std::cin >> subjects[i];
    }

    double average = AverageMarks(subjects);

    char grade = CalculateGrade(average);

    std::cout << "\nAverage: " << average << std::endl;
    std::cout << "Grade: " << grade << std::endl;

    return 0;
}