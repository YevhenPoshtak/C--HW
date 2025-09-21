#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
    double m1 = 62;
    double m2 = 49;
    double r = 1;
    const double G = 6.673e-11;
    long double F = (G * m1 * m2) / (r * r);
    cout << "F = " << scientific << setprecision(6) << F << endl;
    return 0;
}