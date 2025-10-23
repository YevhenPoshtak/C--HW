#include <iostream>
#include <cmath>
using namespace std;

unsigned long long sum(unsigned n, unsigned long long* arr) {
    unsigned long long res = 0;
    for (unsigned i = 0; i < n; ++i)
        res += arr[i];
    return res;
}

int main() {
    unsigned n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Enter " << 10 * n << " digits: ";

    long double num;
    cin >> num; 

    unsigned long long* arr = new unsigned long long[n];

    for (int i = n - 1; i >= 0; --i) {
        unsigned long long part = fmod(num, 10000000000ULL);
        arr[i] = part;
        num = floor(num / 10000000000ULL);
    }

    cout << "Sum = " << sum(n, arr) << endl;

    delete[] arr;
    return 0;
}
