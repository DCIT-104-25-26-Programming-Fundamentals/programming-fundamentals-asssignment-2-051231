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
#include <string>
using namespace std;

const int MAX = 10;

void printMatrix(const int mat[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << mat[i][j];
        }
        cout << endl;
    }
}

void inputMatrix(int mat[MAX][MAX], int rows, int cols, string name) {
    cout << "--- Input for Matrix " << name << " (" << rows << "x" << cols << ") ---" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> mat[i][j];
        }
    }
}

void transposeMatrix(const int input[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = input[i][j];
        }
    }
}

void addMatrices(const int A[MAX][MAX], const int B[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

void multiplyMatrices(const int A[MAX][MAX], const int B[MAX][MAX], int result[MAX][MAX], int rA, int cA, int cB) {
    for (int i = 0; i < rA; i++) {
        for (int j = 0; j < cB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cA; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int choice;
    cout << "=== MATRIX OPERATIONS ===" << endl;
    cout << "1. Transpose Matrix" << endl;
    cout << "2. Add Matrices" << endl;
    cout << "3. Multiply Matrices" << endl;
    cout << "Enter choice (1-3): ";
    cin >> choice;

    if (choice == 1) {
        int r, c;
        cout << "Enter number of rows: ";
        cin >> r;
        cout << "Enter number of columns: ";
        cin >> c;

        int mat[MAX][MAX], transposed[MAX][MAX];
        inputMatrix(mat, r, c, "A");

        transposeMatrix(mat, transposed, r, c);

        cout << endl << "Original Matrix:" << endl;
        printMatrix(mat, r, c);

        cout << endl << "Transposed Matrix:" << endl;
        printMatrix(transposed, c, r);

    } else if (choice == 2) {
        int r, c;
        cout << "Enter number of rows: ";
        cin >> r;
        cout << "Enter number of columns: ";
        cin >> c;

        int A[MAX][MAX], B[MAX][MAX], sum[MAX][MAX];
        inputMatrix(A, r, c, "A");
        inputMatrix(B, r, c, "B");

        addMatrices(A, B, sum, r, c);

        cout << endl << "Matrix A:" << endl;
        printMatrix(A, r, c);

        cout << endl << "Matrix B:" << endl;
        printMatrix(B, r, c);

        cout << endl << "Sum (A + B):" << endl;
        printMatrix(sum, r, c);

    } else if (choice == 3) {
        int rA, cA, rB, cB;
        cout << "Enter rows for Matrix A: ";
        cin >> rA;
        cout << "Enter columns for Matrix A: ";
        cin >> cA;

        cout << "Enter rows for Matrix B: ";
        cin >> rB;
        cout << "Enter columns for Matrix B: ";
        cin >> cB;

        if (cA != rB) {
            cout << "Error: Matrix multiplication impossible. Columns of A must equal rows of B." << endl;
            return 0;
        }

        int A[MAX][MAX], B[MAX][MAX], product[MAX][MAX];
        inputMatrix(A, rA, cA, "A");
        inputMatrix(B, rB, cB, "B");

        multiplyMatrices(A, B, product, rA, cA, cB);

        cout << endl << "Matrix A:" << endl;
        printMatrix(A, rA, cA);

        cout << endl << "Matrix B:" << endl;
        printMatrix(B, rB, cB);

        cout << endl << "Product (A x B):" << endl;
        printMatrix(product, rA, cB);

    } else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
