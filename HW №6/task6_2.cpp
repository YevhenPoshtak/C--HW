#include <iostream>
using namespace std;

void task6_2() {
    int k;
    unsigned n;
    cout << "n = ";
    cin >> n;
    cout << "k = ";
    cin >> k;

    unsigned result = n | (1u << k); 
    cout << "result = " << result << endl;
}

int main() {
    task6_2();
    return 0;
}
