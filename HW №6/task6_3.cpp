#include <iostream>
#include <iomanip> 
using namespace std;

void task6_3() {
    unsigned long long m; 
    unsigned j;           

    cout << "m = ";
    cin >> m;
    cout << "j = ";
    cin >> j;

    if (j >= 64) {
        return;
    }

    unsigned long long result = m & ~(1ULL << j);

    cout << result << endl;
    cout << hex << uppercase << result << endl;
}

int main() {
    task6_3();
    return 0;
}
