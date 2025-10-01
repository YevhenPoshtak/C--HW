#include <iostream>
using namespace std;

unsigned long long fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    unsigned long long f1 = 0, f2 = 1, f = 0;
    for (int i = 2; i <= n; i++) {
        f = f1 + f2;
        f1 = f2;
        f2 = f;
    }
    return f;
}

unsigned greater_than_fib(unsigned long long a) {
    unsigned long long f1 = 0, f2 = 1;
    unsigned index = 1; 

    while (f2 <= a) {
        unsigned long long temp = f1 + f2;
        f1 = f2;
        f2 = temp;
        index++;
    }
    return index;
}
int main() {
    int n;
    cin >> n;
    unsigned long long a;
    cin >> a;
    cout << fib(n)<< endl;
    cout << greater_than_fib(a) << endl;
    return 0;
}
