#include <iostream>
using namespace std;

unsigned max_k(unsigned m) {
    unsigned k = 0;
    unsigned power_of_4 = 1; 
    while (power_of_4 * 4 <= m) {
        power_of_4 *= 4;
        k++;
    }
    return k;
}

int main() {
    unsigned m; 
    cout << "enter m: "; cin >> m;
    cout << "largest k: " << max_k(m) << endl;
    return 0;
}
