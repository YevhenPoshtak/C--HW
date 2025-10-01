#include <cmath>
#include <iostream>
using namespace std;

double exp_taylor(double x, double epsilon) {
    double term = 1.0;            
    double sum = term;             
    int n = 1;

    while (fabs(term) > epsilon) {
        term *= x / n;  
        sum += term;
        n++;
    }

    return sum;
}

double phi_exp_taylor(double x, double epsilon) {
    double term = x;       
    double sum = term;
    int n = 1;

    while (fabs(term) > epsilon) {
        term *= -1 * x * x / n;      
        sum += term / (2*n + 1);     
        n++;
    }

    return sum;
}

int main() {
    double epsilon;
    double x;
    cin >> epsilon;
    cin >> x;

    cout << "exp(" << x << ") = " << exp_taylor(x, epsilon) << "\n";
    cout << "phi_exp(" << x << ") = " << phi_exp_taylor((x, epsilon) << "\n";
    return 0; 
}
