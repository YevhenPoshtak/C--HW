#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cout << "Enter n and m (n, m < 100): ";
    cin >> n >> m;
    
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 99);
    
    vector<vector<int>> matrix(n, vector<int>(m));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = dis(gen);
        }
    }
    
    cout << "Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }
    
    vector<int> result;
    for (int j = 0; j < m; j++) {
        int maxInCol = matrix[0][j];
        for (int i = 1; i < n; i++) {
            maxInCol = max(maxInCol, matrix[i][j]);
        }
        result.push_back(maxInCol);
    }
    
    cout << "\nVector of maximum elements from each column:\n";
    for (int val : result) {
        cout << val << " ";
    }
    cout << "\n";
    
    return 0;
}