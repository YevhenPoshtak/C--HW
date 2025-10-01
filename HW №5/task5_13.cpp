#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    double a[100];
    a[0] = 1;
    a[1] = 1;
    a[2] = 3;

    for (int k = 3; k <= n; k++) {
        a[k] = a[k-3] + a[k-2] / pow(2, k-1);
    }

    double Pn = 1;
    for (int k = 0; k <= n; k++) {
        Pn *= a[k] / pow(3, k);
    }

    cout << "P_" << n << " = " << Pn << endl;
    return 0;
}
