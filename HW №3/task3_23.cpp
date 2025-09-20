#include <iostream>
#include <cmath>
#include <cfloat>
using namespace std;

double sReLU(double tl, double tr, double al, double ar, double x) {
    if (x <= tl) return tl + al * (x - tl);
    if (x < tr) return 0.0;
    return tr + ar * (x - tr);
}

double der_sReLU(double tl, double tr, double al, double ar, double x) {
    if (x < tl) return al;
    if (x > tl && x < tr) return 0.0;
    if (x > tr) return ar;
    return DBL_MAX; 
}

int main() {
    double x, tl, tr, al, ar;
    cout << "Enter x, tl, tr, al, ar: ";
    cin >> x >> tl >> tr >> al >> ar;
    cout << "sReLU(" << x << ") = " << sReLU(tl, tr, al, ar, x) << ", derivative = " << der_sReLU(tl, tr, al, ar, x) << endl;
    return 0;
}
