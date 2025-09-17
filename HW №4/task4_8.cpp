#include<iostream>
#include<cmath>
using namespace std;

double less_than(unsigned n){
    unsigned i = 0;
    while (pow(2, i) <= n) {
        i++;
    }
    return pow(2, i);
}

int main(){
    unsigned n; 
    cout << "enter n: "; cin >> n;
    cout << n << " < " << less_than(n) << endl;
    return 0;
}