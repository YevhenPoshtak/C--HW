#include <iostream>
using namespace std;

double** createMatrix(unsigned n) {
    double** matrix = new double*[n]{0};
    for (unsigned i = 0; i < n; i++) {
        matrix[i] = new double[n]{0}; 
        for (unsigned j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    return matrix;
}

void deleteMatrix(double** matrix, unsigned n) {
    for (unsigned i = 0; i < n; i++)
        delete[] matrix[i];
    delete[] matrix;
}

double** multiplyMatrices(double** A, double** B, unsigned n) {
    double** C = new double*[n];
    for (unsigned i = 0; i < n; i++) {
        C[i] = new double[n]{0};
        for (unsigned j = 0; j < n; j++) {
            for (unsigned k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

void outputMatrix(double** matrix, unsigned n) {
    for (unsigned i = 0; i < n; i++) {
        for (unsigned j = 0; j < n; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

int main() {
    unsigned n;
    cout << "enter size n: ";
    cin >> n;
    cout << "enter first matrix:" << endl;
    double** A = createMatrix(n);
    cout << "enter second matrix:" << endl;
    double** B = createMatrix(n);
    double** C = multiplyMatrices(A, B, n);
    cout << "result of multiplication:" << endl;
    outputMatrix(C, n);
    deleteMatrix(A, n);
    deleteMatrix(B, n);
    deleteMatrix(C, n);
    return 0;
}
