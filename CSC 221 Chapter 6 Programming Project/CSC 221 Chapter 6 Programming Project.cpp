// CSC 221 Chapter 6 Programming Project.cpp : Project 5: Paint Job Estimator
// Write a modular program that estimates the cost of a paint job.  User should be able to enter the number of rooms to be painted, the price of paint per gallon, and the square footage of wall space in each room.
// The program should calculate the number of gallons of paint required, the total labor hours required, and the total cost of the job.  
// <limits> <cmath> are included for input validation and calculations.
// Functions are used to get valid input for the number of rooms, price of paint, and square footage of each room.
// See header comments for details on each function.
// Return zero to indicate successful completion of the program.

#include <iostream>
#include <limits>
#include <cmath> // for ceil() to round up gallons of paint
using namespace std;

// Function to get valid input for the number of rooms
int getNumberOfRooms() {
    int rooms;
    while (true) {
        cout << "Enter the number of rooms to be painted: ";
        cin >> rooms;

        if (cin.fail() || rooms < 1) {
            cin.clear(); // clear the fail state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            cout << "Invalid input! Please enter a number greater than 0 for the number of rooms.\n";
        }
        else {
            return rooms;
        }
    }
}

// Function to get valid input for the price of paint per gallon
double getPriceOfPaint() {
    double price;
    while (true) {
        cout << "Enter the price of paint per gallon: $";
        cin >> price;

        if (cin.fail() || price < 10.00) {
            cin.clear(); // clear the fail state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            cout << "Invalid input! Please enter a price of $10.00 or more per gallon.\n";
        }
        else {
            return price;
        }
    }
}

// Function to get valid square footage for each room
double getSquareFootage(int roomNumber) {
    double sqft;
    while (true) {
        cout << "Enter the square footage of wall space for room #" << roomNumber << ": ";
        cin >> sqft;

        if (cin.fail() || sqft < 0) {
            cin.clear(); // clear the fail state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            cout << "Invalid input! Square footage cannot be negative.\n";
        }
        else {
            return sqft;
        }
    }
}

// Function to calculate the gallons of paint required for a room
double calculateGallonsRequired(double totalSquareFeet) {
    const double coveragePerGallon = 110.0; // 1 gallon covers 110 square feet
    return ceil(totalSquareFeet / coveragePerGallon); // round up to the next whole gallon
}

// Function to calculate the total labor hours required for the job
double calculateLaborHours(double totalSquareFeet) {
    const double hoursPerGallon = 8.0; // 8 hours of labor per gallon
    double gallonsRequired = calculateGallonsRequired(totalSquareFeet);
    return gallonsRequired * hoursPerGallon;
}

// Function to calculate the total cost of the paint job
double calculateTotalCost(double gallonsRequired, double laborHours, double paintPrice) {
    double laborCost = laborHours * 25.00; // $25 per hour
    double paintCost = gallonsRequired * paintPrice;
    return laborCost + paintCost;
}

int main() {
    int numberOfRooms = getNumberOfRooms(); // Get the number of rooms
    double paintPrice = getPriceOfPaint();  // Get the price of paint per gallon

    double totalSquareFeet = 0; // Total square footage of wall space across all rooms

    // Loop through each room to gather square footage data
    for (int i = 1; i <= numberOfRooms; ++i) {
        totalSquareFeet += getSquareFootage(i);
    }

    // Calculate required values
    double gallonsRequired = calculateGallonsRequired(totalSquareFeet);
    double laborHours = calculateLaborHours(totalSquareFeet);
    double paintCost = gallonsRequired * paintPrice;
    double laborCost = laborHours * 25.00;
    double totalCost = calculateTotalCost(gallonsRequired, laborHours, paintPrice);

    // Display the results
    cout << "\n== Paint Job Cost Breakdown ==\n";
    cout << "Gallons of paint required: " << gallonsRequired << " gallons\n";
    cout << "Labor hours required: " << laborHours << " hours\n";
    cout << "Cost of paint: $" << paintCost << endl;
    cout << "Labor charges: $" << laborCost << endl;
    cout << "Total cost of the paint job: $" << totalCost << endl;

    return 0;
}
