#include <iostream>
using namespace std;

double determinant(int n, double matrix[100][100]) {
    if (n == 1){ 
        return matrix[0][0];
    }
    if (n == 2){ 
        return matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0];
    }

    double det = 0;
    double sub[100][100]; 

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
            det += matrix[0][j] * determinant(n - 1, sub);
        }
        else{
            det -= matrix[0][j] * determinant(n - 1, sub);
        }
    }
    return det;
}

int main(){
    int n;
    cout << "Enter matrix size: ";
    cin >> n;
    double matrix[100][100];
    cout << "Enter matrix elements:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
    cout << "Determinant: " << determinant(n, matrix) << endl;
    return 0;
}