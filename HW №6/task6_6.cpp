#include <iostream>
using namespace std;

int main() {
    int x;
    cout << "Enter x: ";
    cin >> x;

    bool y1 = (x & (x - 1)) > 0;
    cout << "y1 = (x & (x-1)) > 0 : " << y1 << endl;

    int y2 = x & (-x);
    cout << "y2 = x & (-x) : " << y2 << endl;

    if((x & (x - 1)) == 0) {
        cout << "x is power of 2" << endl;
    } 
    else {
        cout << "x isn't power of 2" << endl;
    }

    return 0;
}
