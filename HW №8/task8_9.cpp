#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void InputMatrix(double matrix[200][200], unsigned n) {
    for (unsigned i = 0; i < n; i++)
        for (unsigned j = 0; j < n; j++) {
            cout << "Enter element [" << i+1 << "][" << j+1 << "]: ";
            cin >> matrix[i][j];
        }
}

double Determinant(int n, double matrix[200][200]) {
    if (n == 1) {
        return matrix[0][0];
    }
    if (n == 2){
        return matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0];
    }
    double det = 0, sub[200][200];
    for (int j = 0; j < n; j++) {
        for (int i = 1; i < n; i++) {
            int colIndex = 0;
            for (int k = 0; k < n; k++) {
                if (k == j) continue;
                sub[i-1][colIndex] = matrix[i][k];
                colIndex++;
            }
        }
        if (j % 2 == 0){
            det += matrix[0][j] * Determinant(n - 1, sub);
        }
        else{
            det -= matrix[0][j] * Determinant(n - 1, sub);
        }
    }
    return det; 
}

void CofactorMatrix(int n, double matrix[200][200], double cofactor[200][200]) {
    double sub[200][200];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int subRow = 0;
            for (int row = 0; row < n; row++) {
                if (row == i) continue;
                int subCol = 0;
                for (int col = 0; col < n; col++) {
                    if (col == j) continue;
                    sub[subRow][subCol++] = matrix[row][col];
                }
                subRow++;
            }
            if ((i + j) % 2 == 0) {
                cofactor[i][j] = Determinant(n - 1, sub);
        } 
            else {
                cofactor[i][j] = -Determinant(n - 1, sub);
        }
        }
    }
}

void Transpose(int n, double matrix[200][200], double trans[200][200]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            trans[i][j] = matrix[j][i];
}

void InverseMatrix(int n, double matrix[200][200], double inverse[200][200]) {
    double det = Determinant(n, matrix);
    if (det == 0) {
        cout << "Matrix is singular, inverse doesn't exist.\n";
        return;
    }
    double cofactor[200][200], adj[200][200];
    CofactorMatrix(n, matrix, cofactor);
    Transpose(n, cofactor, adj); 
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            inverse[i][j] = adj[i][j] / det;
}

void OutputMatrix(int n, double matrix[200][200]) {
    double det = Determinant(n, matrix);  
    if (fabs(det) < 1e-9) return;          
    cout << "Inverse matrix:\n";           
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << fixed << setprecision(3) << matrix[i][j] << " ";
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter matrix size: ";
    cin >> n;
    double matrix[200][200];
    cout << "Enter matrix elements:\n";
    InputMatrix(matrix, n);
    double inverse[200][200];
    InverseMatrix(n, matrix, inverse);  
    OutputMatrix(n, inverse); 
    return 0;
}


