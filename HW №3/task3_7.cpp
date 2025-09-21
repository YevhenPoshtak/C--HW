#include <iostream>
#include <cmath>
using namespace std;

void solve_quadratic(double a, double b, double c) {
    double D = b*b - 4*a*c;
    if (D > 0) {
        cout << "Quadratic roots: x1 = " << (-b + sqrt(D))/(2*a) << ", x2 = " << (-b - sqrt(D))/(2*a) << endl;
    } else if (D == 0) {
        cout << "Quadratic root: x = " << -b/(2*a) << endl;
    } else {
        cout << "No real roots for quadratic equation\n";
    }
}

void solve_biquadratic(double a, double b, double c) {
    double D = b*b - 4*a*c;
    if (D < 0) {
        cout << "No real roots for bi-quadratic equation\n";
        return;
    }

    double y1 = (-b + sqrt(D)) / (2*a);
    double y2 = (-b - sqrt(D)) / (2*a);

    cout << "Bi-quadratic roots:\n";

    if (y1 >= 0)
        cout << "x = " << sqrt(y1) << ", x = " << -sqrt(y1) << endl;

    if (y2 >= 0 && y2 != y1)
        cout << "x = " << sqrt(y2) << ", x = " << -sqrt(y2) << endl;

    if ((y1 < 0 && y2 < 0) || (y1 == y2 && y1 < 0))
        cout << "No real roots\n";
}

int main() {
    double a,b,c;
    cout << "Enter coefficients a, b, c for quadratic equation(ax^2 + bx + c = 0): ";
    cin >> a >> b >> c;
    solve_quadratic(a,b,c);

    cout << "Enter coefficients a, b, c for bi-quadratic equation (ax^4 + bx^2 + c = 0): ";
    cin >> a >> b >> c;
    solve_biquadratic(a,b,c);

    return 0;
}
