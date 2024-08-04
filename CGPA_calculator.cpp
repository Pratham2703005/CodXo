#include <bits/stdc++.h>
using namespace std;

void calculateGPA();
void calculateCGPA();
void displayMethod();
void displayMenu();

int main()
{
    displayMenu();
    return 0;
}

void displayMenu() {
    int input;
    cout << "--------------------------------------------------------------------------" << endl;
    cout << "                    GPA & CGPA Calculator (Developed by Ohid)             " << endl;
    cout << "--------------------------------------------------------------------------\n" << endl;
    cout << "            MENU:" << endl;
    cout << "                   1. Calculate GPA (Grade Point Average)" << endl;
    cout << "                   2. Calculate CGPA (Cumulative Grade Point Average)" << endl;
    cout << "                   3. Method for calculating GPA & CGPA" << endl;
    cout << "                   4. Exit Application" << endl;
    cout << "--------------------------------------------------------------------------" << endl;

    while (true) {
        cout << "Enter your choice: ";
        cin >> input;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 1 and 4." << endl;
            continue;
        }

        switch (input) {
            case 1:
                calculateGPA();
                break;
            case 2:
                calculateCGPA();
                break;
            case 3:
                displayMethod();
                break;
            case 4:
                cout << "Exiting Application..." << endl;
                return;
            default:
                cout << "You have entered wrong input. Try again!" << endl;
        }
    }
}

void calculateGPA()
{
    int q;
    cout << "-------------- GPA Calculating -----------------" << endl;
    cout << "How many subjects' points do you want to calculate? : ";
    cin >> q;

    if (q <= 0) {
        cout << "Number of subjects must be greater than 0." << endl;
        return;
    }

    vector<float> credits(q);
    vector<float> points(q);

    for (int i = 0; i < q; ++i) {
        cout << "Enter the credit for subject " << i + 1 << ": ";
        cin >> credits[i];
        cout << "Enter the point of subject " << i + 1 << ": ";
        cin >> points[i];
    }

    float totalPoints = 0;
    float totalCredits = 0;

    for (int j = 0; j < q; ++j) {
        totalPoints += credits[j] * points[j];
        totalCredits += credits[j];
    }

    cout << "\nTotal Points: " << totalPoints << " . Total Credits: " << totalCredits << " . Total GPA: " << totalPoints / totalCredits << " ." << endl;

    while (true) {
        int inmenu;
        cout << "\n1. Calculate Again" << endl;
        cout << "2. Go Back to Main Menu" << endl;
        cout << "3. Exit Application" << endl;
        cout << "Your Input: ";
        cin >> inmenu;

        switch (inmenu) {
            case 1:
                calculateGPA();
                return;
            case 2:
                displayMenu();
                return;
            case 3:
                cout << "Exiting Application..." << endl;
                exit(EXIT_SUCCESS);
            default:
                cout << "You have entered wrong input. Try again!" << endl;
        }
    }
}

void calculateCGPA()
{
    int l;
    cout << "-------------- CGPA Calculating -----------------" << endl;
    cout << "How many semester results do you want to input? : ";
    cin >> l;

    if (l <= 0) {
        cout << "Number of semesters must be greater than 0." << endl;
        return;
    }

    vector<float> semesterResults(l);

    for (int i = 0; i < l; ++i) {
        cout << "Enter Semester " << i + 1 << " Result (GPA): ";
        cin >> semesterResults[i];
    }

    float totalGPA = 0;

    for (float gpa : semesterResults) {
        totalGPA += gpa;
    }

    cout << "******** Your CGPA is " << totalGPA / l << " **********" << endl;

    while (true) {
        int inmenu;
        cout << "\n1. Calculate Again" << endl;
        cout << "2. Go Back to Main Menu" << endl;
        cout << "3. Exit Application" << endl;
        cout << "Your Input: ";
        cin >> inmenu;

        switch (inmenu) {
            case 1:
                calculateCGPA();
                return;
            case 2:
                displayMenu();
                return;
            case 3:
                cout << "Exiting Application..." << endl;
                exit(EXIT_SUCCESS);
            default:
                cout << "You have entered wrong input. Try again!" << endl;
        }
    }
}

void displayMethod()
{
    cout << "--------------- Method of Calculating GPA & CGPA ---------------" << endl;
    cout << " GPA = Sum of (Credit * Point) / Total Credits" << endl;
    cout << " CGPA = Sum of GPA / Number of Semesters" << endl;
    cout << "-----------------------------------------------------------------" << endl;

    while (true) {
        int inmenu;
        cout << "\n1. Go Back to Main Menu" << endl;
        cout << "2. Exit Application" << endl;
        cout << "Your Input: ";
        cin >> inmenu;

        switch (inmenu) {
            case 1:
                displayMenu();
                return;
            case 2:
                cout << "Exiting Application..." << endl;
                exit(EXIT_SUCCESS);
            default:
                cout << "You have entered wrong input. Try again!" << endl;
        }
    }
}
