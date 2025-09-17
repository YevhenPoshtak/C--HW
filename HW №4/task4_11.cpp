#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a[100];   
    int n = 0;   
    double x;    
    double a_mean = 0;   
    double g_mean = 1;

    cout << "Enter numbers (0 to stop):" << endl;
    while (true) {
        cout << "a[" << n << "]=";  
        cin >> x;
        if (x == 0) {
            break;  
        } 
        a[n++] = x;         
        a_mean += x; 
        g_mean *= x;         
    }

    cout << "Arithmetic mean: " << double(a_mean) / n << endl;
    cout << "Geometric mean: " << pow(g_mean, 1.0/n)<< endl;

    return 0;
}


