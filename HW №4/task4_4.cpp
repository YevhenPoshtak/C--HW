#include<iostream>
#include<cmath>
using namespace std;

double polynom(unsigned n,double x){
    double res = x;
    for (int i = 1; i < n; i++){
        res +=(i+1)*pow(x,i+1);
    }
    return res;
}
int main(){
    unsigned n;
    double x;
    cout << "n = "; cin >> n;
    cout << "x = "; cin >> x;
    cout << "y = " << polynom(n,x) << endl;
    return 0;
}