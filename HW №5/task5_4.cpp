#include <iostream>
#include <cmath>
using namespace std;

long long factorial(int n) {
    long long res = 1;   
    if (n == 0 || n == 1) {
        return 1;
    }
    for (int i = 2; i <= n; i++) {
        res *= i;
    }
    return res;
}

long double product1(int n) {
    long double p = 1.0;  
    for (int i = 2; i <= n; i++) {
        p *= (1.0 + 1.0 / factorial(i));
    }
    return p;
}

long double product2(int n) {
    long double prod = 1.0;
    for (int i = 1; i <= n; i++) {
        if((1+i)%2 == 0){
            prod *=(1.0 + 1.0/pow(2,i));
        }
        else{
            prod *=(1.0 + -1.0/pow(2,i));
        }
    }
    
    return prod;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "Product1 = " << product1(n) << endl;
    cout << "Product2 = " << product2(n) << endl;
    return 0;
}
