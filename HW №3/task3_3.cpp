#include <iostream>
#include <cmath>
using namespace std;

void task3_3() {
    int a,b,c;
    cout << "Enter three integers: ";
    cin >> a >> b >> c;

    if (abs(a) < 10 && abs(b) < 10 && abs(c) < 10) {
        int res1 = a * b * c;
        long long res2 = (long long)(a * b * c);
        cout << "Product (int): " << res1 << endl;
        cout << "Product (long long): " << res2 << endl;
    } else {
        cout << "Invalid input" << endl;
    }
}

int main(){
    task3_3();
    return 0;
}
