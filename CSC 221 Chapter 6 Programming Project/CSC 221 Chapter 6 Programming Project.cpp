// CSC 221 Chapter 6 Programming Project.cpp : Project 4: Star Search
// Write a modular program that calculates and displays the final score of a contestant in a talent show. The final score is determined by averaging the three middle scores from five judges
// after dropping the highest and lowest scores.
// <iomanip> is used to allow for decimal acceptance in the scores.
// Functions are broken down by task, see header comments for details.
// Return zero to indicate successful completion of the program.

#include <iostream>
#include <iomanip>
using namespace std;

// Functions declared
double getJudgeScore(int judgeNumber);
double findLowest(double a, double b, double c, double d, double e);
double findHighest(double a, double b, double c, double d, double e);
double calcAverage(double a, double b, double c, double d, double e);

int main() {
    double score1, score2, score3, score4, score5;

    cout << "Enter scores from five judges (between 0.0 and 10.0):\n";

    // Get all five scores with validation
    score1 = getJudgeScore(1);
    score2 = getJudgeScore(2);
    score3 = getJudgeScore(3);
    score4 = getJudgeScore(4);
    score5 = getJudgeScore(5);

    // Calculate and display the final average score
    double finalScore = calcAverage(score1, score2, score3, score4, score5);
    cout << fixed << setprecision(2);
    cout << "\nFinal score (average of middle three): " << finalScore << endl;

    return 0;
}

// Function to get and validate a judge's score (handles bad input like 'a')
double getJudgeScore(int judgeNumber) {
    double score;
    while (true) {
        cout << "Judge #" << judgeNumber << ": ";
        cin >> score;

        if (cin.fail()) {
            cin.clear(); // Clear the error state
            cin.ignore(1000, '\n'); // Discard invalid input
            cout << "Invalid input. Please enter a number between 0.0 and 10.0.\n";
        }
        else if (score < 0.0 || score > 10.0) {
            cout << "Invalid score. Please enter a value between 0.0 and 10.0.\n";
        }
        else {
            cin.ignore(1000, '\n'); // Clear any extra input (like spaces)
            return score;
        }
    }
}

// Function to find the lowest score
double findLowest(double a, double b, double c, double d, double e) {
    double lowest = a;
    if (b < lowest) lowest = b;
    if (c < lowest) lowest = c;
    if (d < lowest) lowest = d;
    if (e < lowest) lowest = e;
    return lowest;
}

// Function to find the highest score
double findHighest(double a, double b, double c, double d, double e) {
    double highest = a;
    if (b > highest) highest = b;
    if (c > highest) highest = c;
    if (d > highest) highest = d;
    if (e > highest) highest = e;
    return highest;
}

// Function to calculate the average after dropping highest and lowest
double calcAverage(double a, double b, double c, double d, double e) {
    double total = a + b + c + d + e;
    double lowest = findLowest(a, b, c, d, e);
    double highest = findHighest(a, b, c, d, e);
    return (total - lowest - highest) / 3.0;
}


