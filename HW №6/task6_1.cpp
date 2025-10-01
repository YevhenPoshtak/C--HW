#include <iostream>
using namespace std;

void task6_1() {
    unsigned n;
    cout << "Enter n (n < 64): ";
    cin >> n;

    if (n >= 64) {
        return;
    }

    unsigned long long m = 1ULL << n; 
    cout << "2^" << n << " = " << m << endl;
}

int main() {
    task6_1();
    return 0;
}

