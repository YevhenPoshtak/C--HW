#include <iostream>
#include <cmath>
using namespace std;

double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

double area(double a, double b) {
    return M_PI * a * b;
}

int main() {
    double Cx, Cy, Ax, Ay, Bx, By;
    
    cout << "Center x: "; 
    if (!(cin >> Cx)) return 1;
    cout << "Center y: "; 
    if (!(cin >> Cy)) return 1;
    
    cout << "Point A x: "; 
    if (!(cin >> Ax)) return 1;
    cout << "Point A y: "; 
    if (!(cin >> Ay)) return 1;
    
    cout << "Point B x: "; 
    if (!(cin >> Bx)) return 1;
    cout << "Point B y: "; 
    if (!(cin >> By)) return 1;
    
    double a = distance(Cx, Cy, Ax, Ay);
    double b = distance(Cx, Cy, Bx, By);
    
    if (a <= 0 || b <= 0) {
        cout << "Error: invalid points" << endl;
        return 1;
    }
    
    cout << "Area: " << area(a, b) << endl;
    return 0;
}