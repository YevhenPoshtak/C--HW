#include <iostream>
#include <iomanip> 
using namespace std;

void task6_4(){
    unsigned n;
    cout << "enter n: ";
    cin >> n;
    unsigned long long result = (n >> 24) | (n << 24) | ((n >> 8) & 65280) | ((n << 8) & 16711680);
    cout << result << endl;
    cout << hex << uppercase << showbase << result << endl;
}

int main(){
    task6_4();
    return 0;
}