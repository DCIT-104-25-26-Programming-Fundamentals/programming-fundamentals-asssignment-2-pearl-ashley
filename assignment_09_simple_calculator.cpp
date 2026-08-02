// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// Build a calculator program that runs in the console and performs basic
// arithmetic operations based on the user's input.
//
// -----------------------------------------------------------------------------
// OPERATIONS YOUR CALCULATOR MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Addition          ( + )    e.g.  10 + 3  =  13
//   2. Subtraction       ( - )    e.g.  10 - 3  =  7
//   3. Multiplication    ( * )    e.g.  10 * 3  =  30
//   4. Division          ( / )    e.g.  10 / 3  =  3.33
//   5. Modulus           ( % )    e.g.  10 % 3  =  1  (remainder)
//   6. Exponentiation    ( ^ )    e.g.  2 ^ 8   =  256
//   7. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        SIMPLE CALCULATOR
//   ============================
//   1. Addition
//   2. Subtraction
//   3. Multiplication
//   4. Division
//   5. Modulus
//   6. Exponentiation
//   7. Quit
//   Select an operation (1-7):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Select an operation (1-7): 4
//   Enter first number : 10
//   Enter second number: 3
//   Result: 10 / 3 = 3.33
//
//   Select an operation (1-7): 4
//   Enter first number : 5
//   Enter second number: 0
//   Error: Cannot divide by zero.
//
//   Select an operation (1-7): 7
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Each arithmetic operation MUST be written as its own function.
// - Use a loop so the calculator keeps running until the user selects Quit.
// - Division by zero must be caught and handled with a clear error message
//   (do NOT let the program crash).
// - Use fixed and setprecision(2) to display results to 2 decimal places.
// - Handle invalid menu choices gracefully.
// - For exponentiation use a loop or the pow() function from <cmath>.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

double add(double x, double y) {
    return x + y;
}

double subtract(double x, double y) {
    return x - y;
}

double multiply(double x, double y) {
    return x * y;
}

double divide(double x, double y, bool &error) {
    if (y == 0) {
        error = true;
        return 0;
    }
    error = false;
    return x / y;
}

double calculateModulus(double x, double y, bool &error) {
    if (y == 0) {
        error = true;
        return 0;
    }
    error = false;
    return fmod(x, y);
}

double exponent(double x, double y) {
    return pow(x, y);
}

void printFormatted(double val) {
    if (val == (long long)val) {
        cout << (long long)val;
    } else {
        cout << fixed << setprecision(2) << val;
    }
}

int main() {
    string choice;
    while (true) {
        cout << "\n============================" << endl;
        cout << "     SIMPLE CALCULATOR" << endl;
        cout << "============================" << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Division" << endl;
        cout << "5. Modulus" << endl;
        cout << "6. Exponentiation" << endl;
        cout << "7. Quit" << endl;
        cout << "Select an operation (1-7): ";
        
        getline(cin, choice);
        if (choice == "7" || choice == "Quit" || choice == "quit") {
            cout << "Goodbye!" << endl;
            break;
        }
        
        if (choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5" && choice != "6") {
            cout << "Error: Invalid choice. Please select 1-7." << endl;
            continue;
        }
        
        double num1, num2;
        cout << "Enter first number : ";
        if (!(cin >> num1)) {
            cout << "Error: Please enter valid numerical values." << endl;
            cin.clear();
            string junk;
            cin >> junk;
            cin.ignore();
            continue;
        }
        cout << "Enter second number: ";
        if (!(cin >> num2)) {
            cout << "Error: Please enter valid numerical values." << endl;
            cin.clear();
            string junk;
            cin >> junk;
            cin.ignore();
            continue;
        }
        cin.ignore();
        
        if (choice == "1") {
            double res = add(num1, num2);
            cout << "Result: ";
            printFormatted(num1);
            cout << " + ";
            printFormatted(num2);
            cout << " = ";
            printFormatted(res);
            cout << endl;
        } else if (choice == "2") {
            double res = subtract(num1, num2);
            cout << "Result: ";
            printFormatted(num1);
            cout << " - ";
            printFormatted(num2);
            cout << " = ";
            printFormatted(res);
            cout << endl;
        } else if (choice == "3") {
            double res = multiply(num1, num2);
            cout << "Result: ";
            printFormatted(num1);
            cout << " * ";
            printFormatted(num2);
            cout << " = ";
            printFormatted(res);
            cout << endl;
        } else if (choice == "4") {
            bool error = false;
            double res = divide(num1, num2, error);
            if (error) {
                cout << "Error: Cannot divide by zero." << endl;
            } else {
                cout << "Result: ";
                printFormatted(num1);
                cout << " / ";
                printFormatted(num2);
                cout << " = ";
                cout << fixed << setprecision(2) << res << endl;
            }
        } else if (choice == "5") {
            bool error = false;
            double res = calculateModulus(num1, num2, error);
            if (error) {
                cout << "Error: Cannot divide by zero." << endl;
            } else {
                cout << "Result: ";
                printFormatted(num1);
                cout << " % ";
                printFormatted(num2);
                cout << " = ";
                printFormatted(res);
                cout << endl;
            }
        } else if (choice == "6") {
            double res = exponent(num1, num2);
            cout << "Result: ";
            printFormatted(num1);
            cout << " ^ ";
            printFormatted(num2);
            cout << " = ";
            printFormatted(res);
            cout << endl;
        }
    }
    return 0;
}

