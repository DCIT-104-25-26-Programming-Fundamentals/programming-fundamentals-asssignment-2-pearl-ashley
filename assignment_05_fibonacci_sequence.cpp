// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 5
// =============================================================================
//
// TASK: Fibonacci Sequence Generator
//
// The Fibonacci sequence is a series of numbers where each number is the sum
// of the two numbers before it:
//
//   0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
//
// Write a C++ program with TWO parts, each implemented as a function.
//
// -----------------------------------------------------------------------------
// PART A — Print the First N Terms
// -----------------------------------------------------------------------------
// - Ask the user how many terms (N) to display.
// - Print the first N numbers of the Fibonacci sequence on one line.
//
// Example:
//   How many terms? 7
//   Fibonacci sequence: 0 1 1 2 3 5 8
//
// -----------------------------------------------------------------------------
// PART B — Check if a Number Belongs to the Sequence
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Determine whether that number is a Fibonacci number.
// - Print an appropriate message.
//
// Example:
//   Enter a number to check: 13
//   13 is a Fibonacci number.
//
//   Enter a number to check: 20
//   20 is NOT a Fibonacci number.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use a loop (not recursion) to generate the sequence in both parts.
// - N must be a positive integer. If it is not, print an error message.
// - Each part must be implemented in its own function (see scaffold below).
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
using namespace std;

vector<long long> generateFibonacci(int n) {
    if (n <= 0) return {};
    vector<long long> result;
    long long a = 0, b = 1;
    for (int i = 0; i < n; i++) {
        result.push_back(a);
        long long temp = a + b;
        a = b;
        b = temp;
    }
    return result;
}

bool isFibonacciNumber(long long val) {
    if (val < 0) return false;
    long long a = 0, b = 1;
    while (a < val) {
        long long temp = a + b;
        a = b;
        b = temp;
    }
    return a == val;
}

int main() {
    int n;
    cout << "How many terms? ";
    if (!(cin >> n) || n <= 0) {
        cout << "Error: The number of terms must be a positive integer." << endl;
        return 0;
    }

    vector<long long> sequence = generateFibonacci(n);
    cout << "Fibonacci sequence: ";
    for (size_t i = 0; i < sequence.size(); i++) {
        cout << sequence[i] << (i + 1 == sequence.size() ? "" : " ");
    }
    cout << endl << endl;

    long long checkNum;
    cout << "Enter a number to check: ";
    if (cin >> checkNum) {
        if (isFibonacciNumber(checkNum)) {
            cout << checkNum << " is a Fibonacci number." << endl;
        } else {
            cout << checkNum << " is NOT a Fibonacci number." << endl;
        }
    } else {
        cout << "Error: Please enter a valid integer." << endl;
    }
    return 0;
}

