// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//
// TASK: Student Record Management System
//
// Build a console-based program that stores and manages student information.
// Use a struct to represent each student record containing:
//
//   - name   : the student's full name  (string)
//   - id     : a unique student ID number (int, e.g. 20240001)
//   - scores : a list of scores from multiple assessments (vector<double>)
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Student
//      - Ask the user to enter the student's name and ID.
//      - Ask how many scores to enter, then collect each score one by one.
//      - Save the student record and confirm it was added.
//
//   2. Display All Students
//      - Print a formatted table showing every student's:
//          Name, ID, individual scores, and their average score.
//      - If no students have been added yet, print a message saying so.
//
//   3. Calculate Average Score for a Specific Student
//      - Ask the user to enter a student ID.
//      - Find the student and print their average score.
//      - If the ID is not found, print an error message.
//
//   4. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ================================
//      STUDENT RECORD SYSTEM MENU
//   ================================
//   1. Add student
//   2. Display all students
//   3. Calculate average score
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Student name: Alice Mensah
//   Student ID: 20240001
//   How many scores? 3
//   Enter score 1: 78
//   Enter score 2: 85
//   Enter score 3: 90
//   Student "Alice Mensah" added successfully.
//
//   Enter your choice (1-4): 3
//   Enter student ID: 20240001
//   Alice Mensah's average score: 84.33
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Define a struct called Student (see scaffold below).
// - Store all records in a vector<Student>.
// - Average scores must be rounded to 2 decimal places (use setprecision(2)).
// - Each feature MUST be in its own function.
// - Handle invalid menu choices and missing student IDs gracefully.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Student {
    string name;
    int id;
    vector<double> scores;
};

void addStudent(vector<Student> &students) {
    cout << "Student name: ";
    string name;
    getline(cin, name);
    if (name.empty()) {
        cout << "Error: Student name cannot be empty." << endl;
        return;
    }
    cout << "Student ID: ";
    int studentId;
    if (!(cin >> studentId)) {
        cout << "Error: Student ID must be an integer." << endl;
        cin.clear();
        string junk;
        cin >> junk;
        return;
    }
    cin.ignore();

    for (const auto &s : students) {
        if (s.id == studentId) {
            cout << "Error: A student with ID " << studentId << " already exists." << endl;
            return;
        }
    }

    cout << "How many scores? ";
    int numScores;
    if (!(cin >> numScores) || numScores < 0) {
        cout << "Error: Please enter a valid non-negative integer." << endl;
        cin.clear();
        string junk;
        cin >> junk;
        return;
    }
    cin.ignore();

    vector<double> scores;
    for (int i = 1; i <= numScores; i++) {
        while (true) {
            cout << "Enter score " << i << ": ";
            double sc;
            if (cin >> sc) {
                scores.push_back(sc);
                break;
            } else {
                cout << "Error: Invalid score. Please enter a number." << endl;
                cin.clear();
                string junk;
                cin >> junk;
            }
        }
    }
    cin.ignore();

    Student student = {name, studentId, scores};
    students.push_back(student);
    cout << "Student \"" << name << "\" added successfully." << endl;
}

void displayStudents(const vector<Student> &students) {
    if (students.empty()) {
        cout << "No student records found." << endl;
        return;
    }
    cout << "--------------------------------------------------" << endl;
    cout << left << setw(15) << "Name" 
         << setw(12) << "ID" 
         << setw(15) << "Scores" 
         << setw(8) << "Average" << endl;
    cout << "--------------------------------------------------" << endl;
    for (const auto &s : students) {
        string scoresStr = "";
        for (size_t i = 0; i < s.scores.size(); i++) {
            // check if fractional part is zero
            double sc = s.scores[i];
            if (sc == (int)sc) {
                scoresStr += to_string((int)sc);
            } else {
                scoresStr += to_string(sc);
                // clean up trailing zeros in to_string
                while (!scoresStr.empty() && scoresStr.back() == '0') {
                    scoresStr.pop_back();
                }
                if (!scoresStr.empty() && scoresStr.back() == '.') {
                    scoresStr.pop_back();
                }
            }
            if (i + 1 < s.scores.size()) {
                scoresStr += ", ";
            }
        }
        double avg = 0.0;
        if (!s.scores.empty()) {
            double sum = 0;
            for (double sc : s.scores) {
                sum += sc;
            }
            avg = sum / s.scores.size();
        }
        cout << left << setw(15) << s.name 
             << setw(12) << s.id 
             << setw(15) << scoresStr;
        if (!s.scores.empty()) {
            cout << fixed << setprecision(2) << setw(8) << avg << endl;
        } else {
            cout << setw(8) << "0.00" << endl;
        }
    }
    cout << "--------------------------------------------------" << endl;
}

void calculateAverageForStudent(const vector<Student> &students) {
    cout << "Enter student ID: ";
    int searchId;
    if (!(cin >> searchId)) {
        cout << "Error: Student ID must be an integer." << endl;
        cin.clear();
        string junk;
        cin >> junk;
        return;
    }
    cin.ignore();

    for (const auto &s : students) {
        if (s.id == searchId) {
            if (!s.scores.empty()) {
                double sum = 0;
                for (double sc : s.scores) {
                    sum += sc;
                }
                double avg = sum / s.scores.size();
                cout << s.name << "'s average score: " << fixed << setprecision(2) << avg << endl;
            } else {
                cout << s.name << " has no scores entered." << endl;
            }
            return;
        }
    }
    cout << "Error: Student ID not found." << endl;
}

int main() {
    vector<Student> students;
    string choice;
    while (true) {
        cout << "\n================================" << endl;
        cout << "   STUDENT RECORD SYSTEM MENU" << endl;
        cout << "================================" << endl;
        cout << "1. Add student" << endl;
        cout << "2. Display all students" << endl;
        cout << "3. Calculate average score" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice (1-4): ";
        
        getline(cin, choice);
        if (choice == "4" || choice == "Quit" || choice == "quit") {
            cout << "Goodbye!" << endl;
            break;
        }
        if (choice == "1") {
            addStudent(students);
        } else if (choice == "2") {
            displayStudents(students);
        } else if (choice == "3") {
            calculateAverageForStudent(students);
        } else {
            cout << "Error: Invalid choice. Please select 1-4." << endl;
        }
    }
    return 0;
}

