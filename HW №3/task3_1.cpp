#include <iostream>
using namespace std;

void task3_1(unsigned x) {
    unsigned last_digit   = x % 10;
    unsigned second_digit = (x / 10) % 10;
    unsigned first_digit  = x / 100;

    cout << first_digit << " " << second_digit << " " << last_digit << " " << endl;
    cout << first_digit + second_digit + last_digit << endl;
    cout << last_digit << second_digit << first_digit << endl;
    
}

int main() {
    unsigned x;
    cin >> x;
    if (x > 99 && x < 1000) {
        task3_1(x);
    }
    else {
        cout << "Not a 3-digit number\n";
    }
    return 0;
}