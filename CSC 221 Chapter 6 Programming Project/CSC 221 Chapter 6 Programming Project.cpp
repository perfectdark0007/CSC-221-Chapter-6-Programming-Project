// CSC 221 Chapter 6 Programming Project.cpp : Project 1: Rectangle Properties
// Write a program that calculates the perimeter and area of a rectangle.  It should calculate the perimeter and area of a rectangle based on user input for the length and width and display the results.
// The program should also ask the user if they want to process another rectangle.  If the user enters 'Y' or 'y', the program should repeat the process.  If the user enters 'N' or 'n', the program should end.
// Do not allow the user to enter negative values for the length or width.  If the user enters a negative value, display an error message and ask them to enter a positive value.
// Functions are set up to get the dimensions, calculate the perimeter, calculate the area, display the results, and ask if the user wants to continue.
// See Headers to see the identify each component.
// Return zero to indicate successful completion of the program.

#include <iostream>
using namespace std;

// Functions set
void getDimensions(double& length, double& width);
double calculatePerimeter(double length, double width);
double calculateArea(double length, double width);
void displayResults(double perimeter, double area);
bool askToContinue();

int main() {
    double length, width, perimeter, area;
    char choice;

    do {
        getDimensions(length, width);
        perimeter = calculatePerimeter(length, width);
        area = calculateArea(length, width);
        displayResults(perimeter, area);
    } while (askToContinue());

    cout << "Have a nice day!" << endl;
    return 0;
}

// Input the user's dimensions
void getDimensions(double& length, double& width) {
    do {
        cout << "Enter the length of the rectangle: ";
        cin >> length;
        if (length < 0)
            cout << "Length cannot be negative. Please try again.\n";
    } while (length < 0);

    do {
        cout << "Enter the width of the rectangle: ";
        cin >> width;
        if (width < 0)
            cout << "Width cannot be negative. Please try again.\n";
    } while (width < 0);
}

// Calculate the perimeter
double calculatePerimeter(double length, double width) {
    return 2 * (length + width);
}

// Calculate the area
double calculateArea(double length, double width) {
    return length * width;
}

// Display the results
void displayResults(double perimeter, double area) {
    cout << "Perimeter: " << perimeter << endl;
    cout << "Area: " << area << endl;
}

// Function to process another rectangle
bool askToContinue() {
    char choice;
    cout << "Would you like to process another rectangle? (Y/N): ";
    cin >> choice;
    return (choice == 'Y' || choice == 'y');
}
