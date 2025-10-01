#include <iostream>
using namespace std;

int main() {
    double a;
    cin >> a;   
    
    double S = 0.0;
    int n = 0;

    while (S <= a) {   
        n++;
        S += 1.0 / n;
    }

    cout << "min n = " << n << '\n';
    cout << "S_" << n << " = " << S << " > " << a << '\n';

    return 0;
}
