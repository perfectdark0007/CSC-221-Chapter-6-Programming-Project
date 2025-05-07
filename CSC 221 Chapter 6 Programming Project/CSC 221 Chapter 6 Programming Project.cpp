// CSC 221 Chapter 6 Programming Project.cpp : Project 2: Safest Driving Area
// Write a program that asks the user to enter the number of accidents the five regions: North, South, East, West, and Central.
// The program should then show which region(s) have the lowest accident count and the associated accident number.
// Functions declared to get the number of accidents and to find the region(s) with the lowest accident count.
// Output is coded in case there are multiple regions with the same lowest accident count.
// See Headers for function description.
// Return zero to indicate successful completion of the program.

#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <limits>
using namespace std;

// Convert string to lowercase
string toLower(const string& s) {
    string result = s;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

// Standardize region names (e.g., "north" ? "North")
string formatRegion(const string& input) {
    string lower = toLower(input);
    if (lower == "north") return "North";
    if (lower == "south") return "South";
    if (lower == "east") return "East";
    if (lower == "west") return "West";
    if (lower == "central") return "Central";
    return "";
}

// Get validated accident count
int getAccidentCount(const string& regionName) {
    int accidents;
    while (true) {
        cout << "Enter number of accidents for " << regionName << ": ";
        cin >> accidents;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Enter a non-negative integer.\n";
        }
        else if (accidents < 0) {
            cout << "Accidents cannot be negative.\n";
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return accidents;
        }
    }
}

// Find and display region(s) with lowest accident count
void findLowest(const map<string, int>& data) {
    int minAccidents = numeric_limits<int>::max();
    for (const auto& pair : data) {
        if (pair.second < minAccidents) {
            minAccidents = pair.second;
        }
    }

    cout << "\nRegion(s) with the fewest accidents (" << minAccidents << "):\n";
    for (const auto& pair : data) {
        if (pair.second == minAccidents) {
            cout << "- " << pair.first << endl;
        }
    }
}

int main() {
    set<string> allowedRegions = { "North", "South", "East", "West", "Central" };
    map<string, int> accidentData;

    cout << "=== Safe Driving Area Program ===\n";
    cout << "Please enter accident data for each region (North, South, East, West, Central) in any order.\n";

    while (accidentData.size() < allowedRegions.size()) {
        string input;
        cout << "\nEnter region name (" << 5 - accidentData.size() << " remaining): ";
        getline(cin, input);

        string region = formatRegion(input);

        if (region == "") {
            cout << "Invalid region. Please enter one of: North, South, East, West, Central.\n";
        }
        else if (accidentData.count(region)) {
            cout << "You already entered data for " << region << ".\n";
        }
        else {
            accidentData[region] = getAccidentCount(region);
        }
    }

    findLowest(accidentData);
    return 0;
}