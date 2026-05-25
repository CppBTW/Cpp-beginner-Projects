#include <iostream>

int main()
{
    int age;
    double weight; // Changed to double to allow decimals
    double height; // Changed to double for meters (e.g., 1.75)
    double BMI;

    std::cout << "<======== BMI CALCULATOR ===========>" << std::endl;

    std::cout << "Enter your age: ";
    std::cin >> age;

    std::cout << "Enter your weight in KGs: ";
    std::cin >> weight;

    std::cout << "Enter your height in meters (e.g., 1.75): ";
    std::cin >> height;

    // BMI Formula: weight / (height * height)
    BMI = weight / (height * height);

    std::cout << "\nYour BMI is: " << BMI << std::endl;

    // Logic based on standard adult BMI categories (Age 19+)
    if (age >= 19) {
        if (BMI < 18.5) {
            std::cout << "Category: Underweight" << std::endl;
        } 
        else if (BMI >= 18.5 && BMI < 25.0) {
            std::cout << "Category: Healthy weight" << std::endl;
        } 
        else if (BMI >= 25.0 && BMI < 30.0) {
            std::cout << "Category: Overweight" << std::endl;
        } 
        else {
            std::cout << "Category: Obese" << std::endl;
        }
    } 
    else {
        // Simple fallback for users under 19, as youth BMI requires percentile charts
        std::cout << "Note: Standard BMI categories apply to adults aged 19 and older." << std::endl;
    }

    return 0;
}