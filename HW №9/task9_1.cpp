#include <iostream>
using namespace std;

void array1(unsigned n) {
    double* arr = new double[n];   
    for (unsigned i = 0; i < n; i++) {
        cin >> arr[i];
    }
    double sum = 0;
    for (unsigned j = 0; j < n; j++) {
        sum += arr[j] * arr[j];
    }
    cout << "sum of squares = " << sum << endl;
}

int main() {
    unsigned n;
    cin >> n;
    array1(n);   
    return 0;
}
