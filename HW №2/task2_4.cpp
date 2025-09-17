#include <iostream>
using namespace std;

double polynom(double x) {
    double t = x + 1;      
    double t2 = t * t;     
    double t4 = t2 * t2;   
    return t4 * t;          
}

int main(){
    double x;
    cin >> x;
    cout << "f(" << x << ") = " << polynom(x) << endl;
    return 0;
}