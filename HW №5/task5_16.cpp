#include <iostream>
#include <cmath>
using namespace std;

double cos_x(double x, double eps) {
    double S = 0;     
    double a = 1;     
    int k = 0;        
    while (abs(a) >= eps) {
        S += a;       
        k++;
        a *= -x * x / (2 * k * (2 * k - 1)); 
    }
    return S;
}

int main() {
    double x, eps;
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter epsilon: ";
    cin >> eps;
    cout << "cos(" << x << ") = " << cos_x(x, eps) << endl;
    return 0;
}
