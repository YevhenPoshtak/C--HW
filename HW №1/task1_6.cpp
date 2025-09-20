#include <iostream>
using namespace std;

int main() {
    double c;
    cout << "Enter temperature in Celsius: ";
    cin >> c;
    double f = (9.0 / 5.0) * c + 32.0;
    cout << "F = " << f << endl;
    return 0;
}