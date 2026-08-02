// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLE
// -----------------------------------------------------------------------------
//
//   How many numbers? 5
//   Enter number 1: 4
//   Enter number 2: 7
//   Enter number 3: 2
//   Enter number 4: 9
//   Enter number 5: 1
//
//   Results:
//   Sum:     23
//   Average: 4.6
//   Maximum: 9
//   Minimum: 1
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement each calculation in its own function (see scaffold).
// - You may NOT use any standard library functions like accumulate(), max(),
//   or min(). Implement the logic yourself using loops.
// - N must be a positive integer. If the user enters 0 or a negative number,
//   print an error message and stop.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

double calculateSum(const double numbers[], int size) {
    double total = 0;
    for (int i = 0; i < size; i++) {
        total += numbers[i];
    }
    return total;
}

double calculateAverage(const double numbers[], int size) {
    if (size == 0) {
        return 0.0;
    }
    return calculateSum(numbers, size) / size;
}

double calculateMax(const double numbers[], int size) {
    double maximum = numbers[0];
    for (int i = 1; i < size; i++) {
        if (numbers[i] > maximum) {
            maximum = numbers[i];
        }
    }
    return maximum;
}

double calculateMin(const double numbers[], int size) {
    double minimum = numbers[0];
    for (int i = 1; i < size; i++) {
        if (numbers[i] < minimum) {
            minimum = numbers[i];
        }
    }
    return minimum;
}

int main() {
    int n;
    cout << "How many numbers? ";
    if (!(cin >> n) || n <= 0) {
        cout << "Error: The number of elements must be a positive integer." << endl;
        return 0;
    }

    double* numbers = new double[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter number " << (i + 1) << ": ";
        if (!(cin >> numbers[i])) {
            cout << "Error: Invalid input. Please enter numbers only." << endl;
            delete[] numbers;
            return 0;
        }
    }

    double totalSum = calculateSum(numbers, n);
    double avg = calculateAverage(numbers, n);
    double maximum = calculateMax(numbers, n);
    double minimum = calculateMin(numbers, n);

    cout << "\nResults:" << endl;
    cout << "Sum:     " << totalSum << endl;
    cout << "Average: " << avg << endl;
    cout << "Maximum: " << maximum << endl;
    cout << "Minimum: " << minimum << endl;

    delete[] numbers;
    return 0;
}

