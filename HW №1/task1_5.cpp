#include <iostream>
using namespace std;

int main(){
    double x;
    cin >> x;
    
    double a2 = x * x;
    double a4 = a2 * a2;
    cout << "x^4 = " << a4 << endl;

    double b2 = x * x;
    double b4 = b2 * b2;
    double b6 = b2 * b4;
    cout << "x^6 = " << b6 << endl;

    double c2 = x * x;
    double c4 = c2 * c2;
    double c8 = c4 * c4;
    double c9 = c8 * x;
    cout << "x^9 = " << c9 << endl;

    double d2 = x * x;
    double d3 = d2 * x;
    double d6 = d3 * d3;
    double d12 = d6 * d6;
    double d15 = d12 * d3;
    cout << "x^15 = " << d15 << endl;

    double e2 = x * x;
    double e3 = e2 * x;
    double e6 = e3 * e3;
    double e7 = e6 * x;
    double e14 = e7 * e7;
    double e28 = e14 * 14;
    cout << "x^28 = " << e28 << endl;

    double f2 = x * x;
    double f4 = f2 * f2;
    double f8 = f4 * f4;
    double f16 = f8 * f8;
    double f32 = f16 * f16;
    double f64 = f32 * f32;
    cout << "x^64 = " << f64 << endl;

    return 0;
}