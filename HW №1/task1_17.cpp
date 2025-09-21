#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    long double x;
    cout << "enter real number between 0 and 10000: ";
    cin >> x;

    long double x1 = pow(x, 8);

    long double int_part_20_dig;
    long double frac_part = modfl(x1, &int_part_20_dig);

    int digits = int(floor(log10(int_part_20_dig)) + 1);

    if (digits > 20) {
        long double cut_off = pow(10.0L, digits - 20);
        int_part_20_dig = floor(int_part_20_dig / cut_off);
    }

    int frac_4_dig = int(round(frac_part * 10000));
 
    cout << fixed << setprecision(0) << int_part_20_dig << "." << frac_4_dig << endl;

    return 0;
}
