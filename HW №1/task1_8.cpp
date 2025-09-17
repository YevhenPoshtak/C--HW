#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    double x,y;
    cin >> x;
    cin >> y;
    
    double subtraction = x - y;
    cout << "result of subtraction x and y = " << fixed << setprecision(4) << subtraction << endl;

    double product = x * y;
    cout << "result of product x and y = " << fixed << setprecision(4) << product << endl;

    return 0;
}