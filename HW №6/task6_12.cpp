#include <iostream>
using namespace std;

int main() {
    unsigned int m;
    int i, j;

    cout << "Enter m: ";
    cin >> m;
    if (m == 0) {
        cout << "Incorrect input" << endl;
        return 1;
    }

    cout << "Enter i and j: ";
    cin >> i >> j;

    int bit_i = (m >> i) & 1;
    int bit_j = (m >> j) & 1;

    if (bit_i != bit_j) {
        m ^= (1 << i) | (1 << j);
    }

    cout << "Result in decimal: " << m << endl;
    cout << "Result in hexadecimal: " << hex << m << endl;

    return 0;
}
