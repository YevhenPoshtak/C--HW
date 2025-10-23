#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    unsigned n;
    cout << "Enter n: ";
    cin >> n;

    unsigned m;
    cout << "Enter precision (0 or 2): ";
    cin >> m;

    if (m != 0 && m != 2) {
        cout << "Invalid precision" << endl;
        return 1;
    }

    for (int i = 0; i < n*6; ++i){
        cout << "+";
    }
    cout << "\n";

    for (int i = 1; i <= n; ++i) {
        cout << setw(6) << i;
    }
    cout << "\n";

    for (int i = 0; i < n*6; ++i){
        cout << "+";
    }
    cout << "\n";

    for (int i = 1; i <= n; ++i) {
        cout << fixed << setprecision(m) << setw(6) << sqrt(i);
    }
    cout << "\n";

    for (int i = 0; i < n*6; ++i){
        cout << "+";
    }
    cout << "\n";

    return 0;
}
