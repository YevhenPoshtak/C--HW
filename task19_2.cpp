#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int d;
    cout << "Enter dimension d: ";
    cin >> d;
    
    int n;
    cout << "Enter number of vectors n: ";
    cin >> n;
    
    vector<vector<double>> vectors(n, vector<double>(d));
    
    cout << "Enter " << n << " d-dimensional vectors:\n";
    for (int i = 0; i < n; i++) {
        cout << "Vector " << i + 1 << ": ";
        for (int j = 0; j < d; j++) {
            cin >> vectors[i][j];
        }
    }
    
    vector<double> norms(n);
    for (int i = 0; i < n; i++) {
        double sum = 0;
        for (int j = 0; j < d; j++) {
            sum += vectors[i][j] * vectors[i][j];
        }
        norms[i] = sqrt(sum);
    }
    
    double sumNorms = 0;
    for (int i = 0; i < n; i++) {
        sumNorms += norms[i];
    }
    
    cout << "\nVector norms:\n";
    for (int i = 0; i < n; i++) {
        cout << "Vector " << i + 1 << ": " << norms[i] << "\n";
    }
    cout << "Sum of norms: " << sumNorms << "\n";
    
    return 0;
}