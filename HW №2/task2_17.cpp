#include <iostream>
#include <cmath>
using namespace std;

double identity(double x) {
    const double epsilon = 1e-6;
    
    if (fabs(x) <= 1.0) {
        double term = x;
        double sum = term;
        int n = 1;
        while (fabs(term) > epsilon) {
            term *= -x * x;
            sum += term / (2 * n + 1);
            n++;
        }
        return sum;
    } else {
        if (x > 0)
            return M_PI/2 - identity(1/x);
        else
            return -M_PI/2 - identity(1/x);
    }
}

double identity_derivative(double x) {
    return 1 / (1 + x * x);
}

int main() {
    double x;
    cout << "Enter x: ";
    if (!(cin >> x)) {
        return 0;
    }
    cout << "arctan(x) = " << identity(x) << endl;
    cout << "arctan'(x) = " << identity_derivative(x) << endl;
    return 0;
}
