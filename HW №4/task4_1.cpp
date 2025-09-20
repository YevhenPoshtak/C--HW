#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x;
    unsigned n;
    cout << "x = "; cin >> x;
    cout << "n = "; cin >> n;

    double y = x;
    for (unsigned i = 0; i < n; i++) {
        y = sin(y);
    }
    
    cout << "y = " << y << endl;
    return 0;
}
