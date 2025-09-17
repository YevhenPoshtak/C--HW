#include<iostream>
#include<cmath>
using namespace std;

int is_odd(unsigned n){
     return (n%2 == 1);
}

int last_digit_5(unsigned n){
    return (n%5 == 0) && (n%10 != 0);

}

int multiple_of_m(int n, unsigned m){
    return (abs(n) % m == 0);
}

int multiple_of_both(unsigned n, unsigned k, unsigned m){
    return (n % m == 0) && (k % m == 0);
}

int main(){
    unsigned n,m,k;
    int n1;
    cout << "enter natural n,k,m: ";
    cin >> n >> k >> m;
    cout << "enter integer n1: ";
    cin >> n1;
    cout << "n is odd: "<< is_odd(n) << endl;
    cout << "last digit of n is 5: " << last_digit_5(n) << endl;
    cout << "n1 is multiple of m: " << multiple_of_m(n1,m) << endl;
    cout << "n and k are multiples of m:" << multiple_of_both(n,k,m) << endl;

    return 0;
}