// CSC 221 Chapter 6 Programming Project.cpp : Project 3: Celsius Temperature Table
// Write a modular program that creates a table showing the temperature conversion from Fahrenheit to Celsius between 0 and 20 degrees Fahrenheit.
// <iomanip> is used to format the into columns and to set the precision of the output.
// FahreheittoCelsius uses the formula C = 5/9 * (F - 32) to convert Fahrenheit to Celsius.
// The program uses a for loop to iterate through the Fahrenheit values from 0 to 20 and calls the FahrenheittoCelsius function to convert each value.
// The results are displayed in a formatted table with two columns: Fahrenheit and Celsius.
// Return zero to indicate successful completion of the program.

#include <iostream>
#include <iomanip> // for std::setw and std::setprecision
using namespace std;

// Function declared here
double FahrenheittoCelsius(int fahrenheit);

int main() {
    cout << "Fahrenheit to Celsius Conversion Table (0 - 20 F)\n";
    cout << "---------------------------------------------\n";
    cout << setw(12) << "Fahrenheit" << setw(12) << "Celsius" << endl;
    cout << "---------------------------------------------\n";

    for (int f = 0; f <= 20; ++f) {
        double c = FahrenheittoCelsius(f);
        cout << setw(12) << f << setw(12) << fixed << setprecision(2) << c << endl;
    }

    return 0;
}

// Converts Fahrenheit to Celsius using the formula C = 5/9 * (F - 32)
double FahrenheittoCelsius(int fahrenheit) {
    return 5.0 / 9.0 * (fahrenheit - 32);
}