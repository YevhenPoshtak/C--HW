#include <iostream>
using namespace std;

void InputMatrix(double matrix[25][25], unsigned m, unsigned n) {
    for (unsigned i = 0; i < m; i++) {
        cout << "Enter elements of row " << i + 1 << ":" << endl;
        for (unsigned j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
}

void OutputMatrix(double matrix[25][25], unsigned m, unsigned n) {
    cout << "\nMatrix:" << endl;
    for (unsigned i = 0; i < m; i++) {
        for (unsigned j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    unsigned m, n;
    cout << "Enter matrix size (m n): ";
    cin >> m >> n;
    double matrix[25][25];
    InputMatrix(matrix, m, n);
    OutputMatrix(matrix, m, n);
    return 0;
}
