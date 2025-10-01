#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    
    double a[100], b[100]; 
    a[1] = 0; 
    a[2] = 1;
    b[1] = 1; 
    b[2] = 0;

    for (int k = 3; k <= n; k++) {
        a[k] = k * a[k-1] + a[k-2] * b[k-1];
        b[k] = b[k-1] + a[k-1];
    }

    double Sn = 0;
    for (int k = 1; k <= n; k++) {
        Sn += pow(2, k) / (a[k] + b[k]);
    }

    cout << "S_" << n << " = " << Sn << endl;
    return 0;
}
