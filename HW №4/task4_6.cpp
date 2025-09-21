#include <iostream>
#include <cmath>
using namespace std;

int main() {
    unsigned n;
    cout << "Введіть n: ";
    cin >> n;

    double sum1 = 0;
    for (unsigned i = 0; i < n; i++) {
        sum1 += sqrt(2);
    }
    cout << "S1 = " << sum1 << endl;

    double sum2 = 0;
    for (unsigned i = 1; i <= n; i++) {
        sum2 += sqrt(3 * i);
    }
    cout << "S2 = " << sum2 << endl;

    return 0;
}
