#include<iostream>
using namespace std;

int main() {
    unsigned n, m;
    cin >> n >> m;

    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    for(int i = 0; i < 3; i++ ){
        for(int j = 0; j < 3; j++){
            if(matrix[i][j] == m){
                matrix[i][j] = n;
            }
        }
    }
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
