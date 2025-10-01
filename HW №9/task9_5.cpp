#include <iostream>
#include <cmath>
using namespace std;

int** createMatrix(unsigned n) {
    int** matrix = new int*[n];
    for (unsigned i = 0; i < n; i++) {
        matrix[i] = new int[n];
    }
    for (unsigned i = 0; i < n; i++) {
        for (unsigned j = 0; j < n; j++) {
            cout << "Enter element [" << i+1 << "][" << j+1 << "]: ";
            cin >> matrix[i][j];
        }
    }
    return matrix;
}

void deleteMatrix(int** matrix, unsigned n) {
    for (unsigned i = 0; i < n; i++){
        delete[] matrix[i];
    }
    delete[] matrix;
}

double determinant(int** matrix, int n) {
    if (n == 1){
        return matrix[0][0];
    }
    if (n == 2){
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }
    double det = 0;
    int** sub = new int*[n - 1];
    for (int i = 0; i < n - 1; i++)
        sub[i] = new int[n - 1];
    for (int j = 0; j < n; j++) {
        for (int row = 1; row < n; row++) {
            int colIndex = 0;
            for (int col = 0; col < n; col++) {
                if (col == j) continue;
                sub[row - 1][colIndex] = matrix[row][col];
                colIndex++;
            }
        }
        if (j % 2 == 0)
            det += matrix[0][j] * determinant(sub, n - 1);
        else
            det -= matrix[0][j] * determinant(sub, n - 1);
    }

    for (int i = 0; i < n - 1; i++){
        delete[] sub[i];
    }
    delete[] sub;
    return det;
}

int rankMatrix(int** a, int n) {
    double** m = new double*[n];
    for (int i = 0; i < n; i++) {
        m[i] = new double[n];
        for (int j = 0; j < n; j++){
            m[i][j] = a[i][j];
        }
    }
    int r = 0;
    for (int c = 0, row = 0; c < n && row < n; c++) {
        int p = row;
        while (p < n && fabs(m[p][c]) < 1e-9) p++;
        if (p == n){
            continue;
        }
        double* t = m[p]; m[p] = m[row]; m[row] = t;
        for (int i = row + 1; i < n; i++) {
            double f = m[i][c] / m[row][c];
            for (int j = c; j < n; j++){
                m[i][j] -= f * m[row][j];
            }
        }
        r++; row++;
    }
    for (int i = 0; i < n; i++){ 
        delete[] m[i];
    }
    delete[] m;
    return r;
}

int main() {
    unsigned n;
    cout << "Enter size of matrix: ";
    cin >> n;
    int** matrix = createMatrix(n);
    cout << "Determinant = " << determinant(matrix, n) << endl;
    cout << "Rank = " << rankMatrix(matrix, n) << endl;
    deleteMatrix(matrix, n);
    return 0;
}
