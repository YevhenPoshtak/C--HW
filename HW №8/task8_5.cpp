#include <iostream>
using namespace std;

void InputMatrix(double matrix[100][100], unsigned n) {
    for (unsigned i = 0; i < n; i++) {
        for (unsigned j = 0; j < n; j++) {
            cout << "Enter element [" << i+1 << "][" << j+1 << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void OutputTranspose(double matrix[100][100], unsigned n) {
    cout << "\nTransposed Matrix:" << endl;
    for (unsigned i = 0; i < n; i++) {
        for (unsigned j = 0; j < n; j++) {
            cout << matrix[j][i] << " ";
        }
        cout << endl;
    }
}

int main() {
    unsigned n;
    cout << "Enter matrix size (n): ";
    cin >> n;
    double matrix[100][100];
    InputMatrix(matrix, n);
    OutputTranspose(matrix, n);
    return 0;
}
