#include <iostream>
using namespace std;

void task3_6(double x, double y, double z) {
    double max_abs, min_abs;

    if (abs(x) > abs(y) && abs(x) > abs(z)) {
        max_abs = x;
    } 
    else if (abs(y) > abs(x) && abs(y) > abs(z)) {
        max_abs = y;
    } 
    else {
        max_abs = z;
    }

    if (abs(x) < abs(y) && abs(x) < abs(z)) {
        min_abs = x;
    } 
    else if (abs(y) < abs(x) && abs(y) < abs(z)) {
        min_abs = y;
    } 
    else {
        min_abs = z;
    }

    cout << "Minimum abs: " << min_abs << endl;
    cout << "Maximum abs: " << max_abs << endl;
}
int main(){
    double x,y,z;
    cin >> x >> y >> z;
    task3_6(x,y,z);
    return 0;
}
