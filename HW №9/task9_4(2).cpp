#include <iostream>
using namespace std;

double* createLinearMatrix(unsigned n) {
    double* matrix = new double[n*n]{0}; 
    for (unsigned i = 0; i < n; i++)
        for (unsigned j = 0; j < n; j++)
            cin >> matrix[i*n + j]; 
    return matrix;
}

void deleteLinearMatrix(double* matrix) {
    delete[] matrix;
}

double* multiplyLinearMatrices(double* A, double* B, unsigned n) {
    double* C = new double[n*n]{0};
    for (unsigned i = 0; i < n; i++)
        for (unsigned j = 0; j < n; j++)
            for (unsigned k = 0; k < n; k++)
                C[i*n + j] += A[i*n + k] * B[k*n + j];
    return C;
}

void outputLinearMatrix(double* matrix, unsigned n) {
    for (unsigned i = 0; i < n; i++) {
        for (unsigned j = 0; j < n; j++)
            cout << matrix[i*n + j] << " ";
        cout << endl;
    }
}

int main() {
    unsigned n;
    cout << "enter size n: ";
    cin >> n;
    cout << "enter first matrix:" << endl;
    double* A = createLinearMatrix(n);
    cout << "enter second matrix:" << endl;
    double* B = createLinearMatrix(n);
    double* C = multiplyLinearMatrices(A, B, n);
    cout << "result of multiplication:" << endl;
    outputLinearMatrix(C, n);
    deleteLinearMatrix(A);
    deleteLinearMatrix(B);
    deleteLinearMatrix(C);
    return 0;
}
