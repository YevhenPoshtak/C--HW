#include <iostream>
#include <cmath>
using namespace std;

unsigned fact(int n) {
    unsigned res = 1;
    for (int i = 1; i <= n; i++) {
        res *= i;
    }
    return res;
}

unsigned sub_fact(int n) {
    double sum = 0.0;
    for (int i = 0; i <= n; i++) {
        sum += pow(-1, i) / fact(i);  
    }
    unsigned res = fact(n) * sum;  
    return res;
}

int main() {
    int n; cin >> n;
    cout << "!" << n << " = " << sub_fact(n) << endl;
}
