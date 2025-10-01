#include <iostream>
using namespace std;

void rev() {
    int num[4] = {5, 112, 4, 3};
    int n = 4;
    int rev[4];

    for (int i = 0; i < n; i++) {
        rev[i] = num[n - i - 1];
    }

    for (int i = 0; i < n; i++) {
        cout << rev[i] ;
    }
}

int main() {
    rev(); 
    return 0;
}
