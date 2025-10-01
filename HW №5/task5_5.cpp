#include <iostream>
using namespace std;

int main() {
    int x1 = -99, x2 = -99, x3 = -99, xn, n = 3;
    while (true) {
        n++;
        xn = x3 + x1 + 100;
        x1 = x2;
        x2 = x3;
        x3 = xn;
        if (xn > 0){
            break;
        }
    }
    cout << "n = " << n << ", x_n = " << xn << endl;
    return 0;
}
