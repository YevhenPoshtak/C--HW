#include <iostream>
using namespace std;

double** InputMatrix(unsigned m, unsigned n) {
    double** matrix = new double*[m];
    for (unsigned i = 0; i < m; i++) {
        matrix[i] = new double[n];
        for (unsigned j = 0; j < n; j++) {
            cout << "Enter element [" << i+1 << "][" << j+1 << "]: ";
            cin >> matrix[i][j];
        }
    }
    return matrix;
}

void PrintMatrix(double** matrix, unsigned m, unsigned n) {
    cout << "\nMatrix:" << endl;
    for (unsigned i = 0; i < m; i++) {
        for (unsigned j = 0; j < n; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void DeleteMatrix(double** matrix, unsigned m) {
    for (unsigned i = 0; i < m; i++)
        delete[] matrix[i];
    delete[] matrix;
}

double** addRows(double** matrix, unsigned m, unsigned n, unsigned k) {
    double** newMatrix = new double*[m + k];
    for (unsigned i = 0; i < m; i++) {
        newMatrix[i] = new double[n];
        for (unsigned j = 0; j < n; j++) {
            newMatrix[i][j] = matrix[i][j];
        }
    }
    for (unsigned i = m; i < m + k; i++) {
        newMatrix[i] = new double[n];
        for (unsigned j = 0; j < n; j++) {
            cout << "Enter element [" << i+1 << "][" << j+1 << "]: ";
            cin >> newMatrix[i][j];
        }
    }
    DeleteMatrix(matrix, m);
    return newMatrix;
}


int main() {
    unsigned m, n, k;
    cout << "Enter matrix size (m n): ";
    cin >> m >> n;
    double** matrix = InputMatrix(m, n);
    PrintMatrix(matrix, m, n);
    cout << "Enter number of rows to add: ";
    cin >> k;
    matrix = addRows(matrix, m, n, k);
    m += k;
    PrintMatrix(matrix, m, n);
    DeleteMatrix(matrix, m);
    return 0;
}
