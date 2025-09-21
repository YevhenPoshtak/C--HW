#include <iostream>
#include <cmath> 
using namespace std;

int main() {
    double x;
    cin >> x;

    int int_part = x;
    cout << "int part of x = " << int_part << endl;

    int int_part_math = trunc(x);
    cout << "int part of x using cmath = " << int_part_math << endl;
    cout << endl;

    double frac_part = x - int_part;
    cout << "frac part of x = " << frac_part << endl;

    double int_part2;
    double frac_part_math = modf(x, &int_part2);
    cout << "frac part of x using cmath = " << frac_part_math << endl;

    double ceil_num;
    if (x > int_part && x > 0) { 
        ceil_num = int_part + 1;
    } else {
        ceil_num = int_part;
    }
    cout << "Ceiled num x = " << ceil_num << endl;

    double ceil_num_math = ceil(x);
    cout << "Ceiled num x using cmath = " << ceil_num_math << endl;
    cout << endl;

    double floor_num;
    if (x < 0 && x != int_part) { 
        floor_num = int_part - 1;
    } else {
        floor_num = int_part;
    }
    cout << "floored num x = " << floor_num << endl;

    double floor_num_math = floor(x);
    cout << "floored num x using cmath = " << floor_num_math << endl;
    cout << endl;

    double round_num;
    if (x >= 0) {
        round_num = int(x + 0.5);
    } else {
        round_num = int(x - 0.5);
    }
    cout << "result of rounding x = " << round_num << endl;

    double round_num_math = round(x);
    cout << "result of rounding x using cmath = " << round_num_math << endl;

    return 0;
}