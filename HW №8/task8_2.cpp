#include<iostream>
using namespace std;

int main() {
    unsigned i, j;
    cin >> i >> j;
    double a;
    cin >> a;
    double matrix[3][3] = {
        {1.0, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    if (i < 3 && j < 3) {
        matrix[i][j] = a;
    }
    else {
        return 1;
    }
    
    for (int c = 0; c < 3; c++) {
        for (int d = 0; d < 3; d++) {
            cout << matrix[c][d] << " ";
        }
        cout << endl;
    }

    return 0;
}
