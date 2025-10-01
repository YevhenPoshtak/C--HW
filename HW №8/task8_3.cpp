#include <iostream>
using namespace std;

void InputMatrix(double matrix[20][20], unsigned m, unsigned n) {
    for (unsigned i = 0; i < m; i++)
        for (unsigned j = 0; j < n; j++) {
            cout << "Enter element [" << i+1 << "][" << j+1 << "]: ";
            cin >> matrix[i][j];
        }
}

void OutputMatrix(double matrix[20][20], unsigned m, unsigned n) {
    cout << "\nMatrix:" << endl;
    for (unsigned i = 0; i < m; i++) {
        for (unsigned j = 0; j < n; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

int main() {
    unsigned m, n;
    cout << "Enter matrix size (m n): ";
    cin >> m >> n;
    double matrix[20][20];
    InputMatrix(matrix, m, n);
    OutputMatrix(matrix, m, n);
    return 0;
}
