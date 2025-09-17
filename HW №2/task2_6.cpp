#include <iostream>
#include <cmath>
using namespace std;

double len(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

double perimeter(double a, double b, double c) {
    return a + b + c;
}

double area(double a, double b, double c) {
    double p = perimeter(a, b, c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

int main() {
    double x1, y1;
    cout << "enter first coordinates: ";
    cin >> x1 >> y1;

    double x2, y2;
    cout << "enter second coordinates: ";
    cin >> x2 >> y2;

    double x3, y3;
    cout << "enter third coordinates: ";
    cin >> x3 >> y3;

    double a = len(x1, y1, x2, y2);
    double b = len(x2, y2, x3, y3);
    double c = len(x3, y3, x1, y1);

    cout << "area of triangle = " << area(a, b, c) << endl;

    return 0;
}
