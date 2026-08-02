// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_SIZE = 10;

void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

bool readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int &rows, int &cols, const string &name) {
    cout << "Enter number of rows for " << name << ": ";
    if (!(cin >> rows) || rows <= 0 || rows > MAX_SIZE) {
        cout << "Error: Dimensions must be between 1 and " << MAX_SIZE << "." << endl;
        return false;
    }
    cout << "Enter number of columns for " << name << ": ";
    if (!(cin >> cols) || cols <= 0 || cols > MAX_SIZE) {
        cout << "Error: Dimensions must be between 1 and " << MAX_SIZE << "." << endl;
        return false;
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            if (!(cin >> matrix[i][j])) {
                cout << "Error: Invalid numerical input." << endl;
                return false;
            }
        }
    }
    return true;
}

void transposeMatrix(const int src[MAX_SIZE][MAX_SIZE], int rows, int cols, int dst[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            dst[j][i] = src[i][j];
        }
    }
}

bool addMatrices(const int A[MAX_SIZE][MAX_SIZE], int rA, int cA, const int B[MAX_SIZE][MAX_SIZE], int rB, int cB, int result[MAX_SIZE][MAX_SIZE]) {
    if (rA != rB || cA != cB) {
        return false;
    }
    for (int i = 0; i < rA; i++) {
        for (int j = 0; j < cA; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    return true;
}

bool multiplyMatrices(const int A[MAX_SIZE][MAX_SIZE], int rA, int cA, const int B[MAX_SIZE][MAX_SIZE], int rB, int cB, int result[MAX_SIZE][MAX_SIZE]) {
    if (cA != rB) {
        return false;
    }
    for (int i = 0; i < rA; i++) {
        for (int j = 0; j < cB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cA; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return true;
}

int main() {
    int choice;
    while (true) {
        cout << "\n============================" << endl;
        cout << "   MATRIX OPERATIONS MENU" << endl;
        cout << "============================" << endl;
        cout << "1. Transpose a Matrix (Part A)" << endl;
        cout << "2. Add Two Matrices (Part B)" << endl;
        cout << "3. Multiply Two Matrices (Part C)" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice (1-4): ";
        
        if (!(cin >> choice)) {
            cout << "Invalid choice. Please select 1-4." << endl;
            cin.clear();
            string junk;
            cin >> junk;
            continue;
        }
        
        if (choice == 4) {
            cout << "Goodbye!" << endl;
            break;
        }
        
        if (choice == 1) {
            int matrix[MAX_SIZE][MAX_SIZE];
            int transposed[MAX_SIZE][MAX_SIZE];
            int r, c;
            cout << "\n--- Part A: Transpose a Matrix ---" << endl;
            if (readMatrix(matrix, r, c, "Matrix")) {
                cout << "\nOriginal Matrix:" << endl;
                printMatrix(matrix, r, c);
                transposeMatrix(matrix, r, c, transposed);
                cout << "\nTransposed Matrix:" << endl;
                printMatrix(transposed, c, r);
            }
        } else if (choice == 2) {
            int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], Sum[MAX_SIZE][MAX_SIZE];
            int rA, cA, rB, cB;
            cout << "\n--- Part B: Add Two Matrices ---" << endl;
            cout << "Enter details for Matrix A:" << endl;
            if (readMatrix(A, rA, cA, "Matrix A")) {
                cout << "Enter details for Matrix B:" << endl;
                if (readMatrix(B, rB, cB, "Matrix B")) {
                    cout << "\nMatrix A:" << endl;
                    printMatrix(A, rA, cA);
                    cout << "\nMatrix B:" << endl;
                    printMatrix(B, rB, cB);
                    if (addMatrices(A, rA, cA, B, rB, cB, Sum)) {
                        cout << "\nSum Matrix:" << endl;
                        printMatrix(Sum, rA, cA);
                    } else {
                        cout << "\nError: Matrices must have the same dimensions for addition." << endl;
                    }
                }
            }
        } else if (choice == 3) {
            int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], Prod[MAX_SIZE][MAX_SIZE];
            int rA, cA, rB, cB;
            cout << "\n--- Part C: Multiply Two Matrices ---" << endl;
            cout << "Enter details for Matrix A:" << endl;
            if (readMatrix(A, rA, cA, "Matrix A")) {
                cout << "Enter details for Matrix B:" << endl;
                if (readMatrix(B, rB, cB, "Matrix B")) {
                    cout << "\nMatrix A:" << endl;
                    printMatrix(A, rA, cA);
                    cout << "\nMatrix B:" << endl;
                    printMatrix(B, rB, cB);
                    if (multiplyMatrices(A, rA, cA, B, rB, cB, Prod)) {
                        cout << "\nProduct Matrix:" << endl;
                        printMatrix(Prod, rA, cB);
                    } else {
                        cout << "\nError: Multiplication not possible. Columns in A must equal rows in B." << endl;
                    }
                }
            }
        } else {
            cout << "Invalid choice. Please select 1-4." << endl;
        }
    }
    return 0;
}

