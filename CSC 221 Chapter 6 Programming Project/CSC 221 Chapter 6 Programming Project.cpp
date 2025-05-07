// CSC 221 Chapter 6 Programming Project.cpp : Project 1: Rectangle Properties
// Write a program that calculates the perimeter and area of a rectangle.  It should calculate the perimeter and area of a rectangle based on user input for the length and width and display the results.
// The program should also ask the user if they want to process another rectangle.  If the user enters 'Y' or 'y', the program should repeat the process.  If the user enters 'N' or 'n', the program should end.
// Do not allow the user to enter negative values for the length or width.  If the user enters a negative value, display an error message and ask them to enter a positive value.
// Functions are set up to get the dimensions, calculate the perimeter, calculate the area, display the results, and ask if the user wants to continue.
// See Headers to see the identify each component.
// Return zero to indicate successful completion of the program.

#include <iostream>
#include <limits>
using namespace std;

// Function to get a valid dimension (length or width)
double getRectangleDimension(const string& dimensionName) {
    double value;
    while (true) {
        cout << "Enter the " << dimensionName << ": ";
        cin >> value;

        if (cin.fail()) {
            cin.clear(); // clear the fail state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            cout << "Invalid input! Please enter a positive number.\n";
        }
        else if (value < 0) {
            cout << "The " << dimensionName << " cannot be negative. Please enter a valid positive number.\n";
        }
        else {
            return value; // valid input, return the value
        }
    }
}

// Function to calculate and display the perimeter and area of the rectangle
void calculateRectangle(double length, double width) {
    double perimeter = 2 * (length + width);
    double area = length * width;

    cout << "\nFor a rectangle with length " << length << " and width " << width << ":\n";
    cout << "Perimeter: " << perimeter << endl;
    cout << "Area: " << area << endl;
}

int main() {
    double length, width;
    char repeat = 'y';

    // Loop to keep processing rectangles until user decides to quit
    while (repeat == 'y' || repeat == 'Y') {
        // Get valid dimensions for the rectangle
        length = getRectangleDimension("length");
        width = getRectangleDimension("width");

        // Calculate and display the perimeter and area
        calculateRectangle(length, width);

        // Ask the user if they want to process another rectangle
        cout << "\nDo you want to process another rectangle? (y/n): ";
        cin >> repeat;

        // Validate response for continuation
        while (repeat != 'y' && repeat != 'Y' && repeat != 'n' && repeat != 'N') {
            cout << "Invalid input! Please enter 'y' for yes or 'n' for no: ";
            cin >> repeat;
        }
    }

    cout << "Program has ended. Goodbye!\n";
    return 0;
}
