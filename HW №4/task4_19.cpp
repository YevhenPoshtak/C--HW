#include <iostream>
using namespace std;

double product(unsigned n) {
    double prod = 2.0;
    for (unsigned i = 2; i <= n; i++) {
        prod *= (1 + 1.0 / (i * i));
    }
    return prod;
}

int main() {
    unsigned n;
    cout << "enter n: ";
    cin >> n;
    cout << "product = " << product(n) << endl;
    return 0;
}