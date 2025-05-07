// CSC 221 Chapter 6 Programming Project.cpp : Project 2 - Safest Driving Area
// Write a program that asks the user to enter the number of accidents the five regions: North, South, East, West, and Central.
// The program should then show which region(s) have the lowest accident count and the associated accident number.
// Functions declared to get the number of accidents and to find the region(s) with the lowest accident count.
// Output is coded in case there are multiple regions with the same lowest accident count.
// See Headers for function description.
// Return zero to indicate successful completion of the program.

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

// Function declarations
int getAccidentCount(const string& regionName);
void findLowest(const map<string, int>& accidentData);

int main() {
    map<string, int> accidentData;
    string region;
    int accidents;

    cout << "Enter accident data for the following 5 regions: North, South, East, West, and Central.\n";

    while (accidentData.size() < 5) {
        cout << "\nEnter region name: ";
        getline(cin, region);

        // Normalize and validate input
        for (auto& c : region) c = tolower(c);
        if (region == "north" || region == "south" || region == "east" ||
            region == "west" || region == "central") {
            region[0] = toupper(region[0]);
        }
        else {
            cout << "Invalid region name. Please enter either: North, South, East, West, Central.\n";
            continue;
        }

        if (accidentData.find(region) != accidentData.end()) {
            cout << "You've already entered data for the " << region << " region.\n";
            continue;
        }

        accidents = getAccidentCount(region);
        accidentData[region] = accidents;
    }

    findLowest(accidentData);

    return 0;
}

//  User-defined function to get the number of accidents for a region
int getAccidentCount(const string& regionName) {
    int accidents;
    do {
        cout << "Enter the number of accidents in the " << regionName << " region: ";
        cin >> accidents;
        cin.ignore(); // Clear newline character from input buffer
        if (accidents < 0)
            cout << "Number cannot be negative. Please try again.\n";
    } while (accidents < 0);

    return accidents;
}

// Determines and displays all regions with the fewest accidents
void findLowest(const map<string, int>& accidentData) {
    // Find the lowest accident count
    int lowestCount = min_element(accidentData.begin(), accidentData.end(),
        [](const auto& a, const auto& b) {
            return a.second < b.second;
        })->second;

    // Display all regions with that lowest count
    cout << "\nRegion(s) with the fewest accidents (" << lowestCount << "):\n";
    for (const auto& pair : accidentData) {
        if (pair.second == lowestCount) {
            cout << "- " << pair.first << endl;
        }
    }
}