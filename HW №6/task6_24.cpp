#include <iostream>
using namespace std;

int main() {
    unsigned int n;
    cout << "Enter a 32-bit number: ";
    cin >> n;

    if (!cin || n == 0) { 
        cout << "Number must be 32-bit and not 0." << endl;
        return 1;
    }

    int lsb = 0;
    unsigned int temp = n;
    while ((temp & 1) == 0) {
        temp >>= 1;
        lsb++;
    }

    int msb = 31;
    temp = n;
    while ((temp & (1U << 31)) == 0) {
        temp <<= 1;
        msb--;
    }

    cout << "LSB position: " << lsb << endl;
    cout << "MSB position: " << msb << endl;

    return 0;
}
