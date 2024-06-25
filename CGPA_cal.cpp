
//CGPA CALCULATOR C++


#include <iostream>
#include <string>
using namespace std;

// Function to convert percentage to grade points (on a 4.0 scale)
double percentageToGradePoint(double percentage) {
    if (percentage >= 85) {
        return 4.0;
    } else if (percentage >= 72) {
        return 3.0;
    } else {
        return (percentage / 100) * 4.0;
    }
}

int main() {
    const int numSubjects = 6;
    string subjects[numSubjects] = {"Programming Fundamentals", "English", "Maths", "Computer Network", "Statistics", "Islamiyat"};
    double marks[numSubjects];
    double creditHours[numSubjects] = {4, 3, 3, 3, 3, 2}; // Credit hours for each subject
    double maxMarks[numSubjects] = {100, 100, 100, 100, 100, 50}; // Max marks for each subject
    double totalCreditHours = 0.0;
    double weightedSum = 0.0;

    // Input marks for each subject
    for(int i = 0; i < numSubjects; i++) {
        cout << "Enter marks for " << subjects[i] << " (out of " << maxMarks[i] << "): ";
        cin >> marks[i];

        // Check if the input marks are within the valid range
        while(marks[i] < 0 || marks[i] > maxMarks[i]) {
            cout << "Invalid marks! Please enter marks between 0 and " << maxMarks[i] << ": ";
            cin >> marks[i];
        }

        // Calculate total credit hours
        totalCreditHours += creditHours[i];

        // Normalize marks to a percentage
        double percentage = (marks[i] / maxMarks[i]) * 100;

        // Convert normalized marks to grade points and add to weighted sum
        weightedSum += percentageToGradePoint(percentage) * creditHours[i];
    }

    // Calculate CGPA
    double cgpa = weightedSum / totalCreditHours;

    // Output the CGPA
    cout << "The CGPA is: " << cgpa << endl;

    return 0;
}
