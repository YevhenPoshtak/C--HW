#include <iostream>
#include <cmath>
using namespace std;

class QuadraticEquation {
public:
    double a, b, c;

    QuadraticEquation() : a(1), b(1), c(1) {}
    QuadraticEquation(double a_, double b_, double c_) : a(a_), b(b_), c(c_) {}

    void solve(double &x1, double &x2, bool &hasRealRoots) {
        if (a == 0) {
            hasRealRoots = false;
            return;
        }
        double D = b*b - 4*a*c;

        if (D < 0) {
            hasRealRoots = false;
            return;
        }

        hasRealRoots = true;

        if (D == 0) {  
            x1 = x2 = -b / (2*a);
        } 
        else {
            x1 = (-b + sqrt(D)) / (2*a);
            x2 = (-b - sqrt(D)) / (2*a);
        }
    }

    double critical_point() {
        return -b / (2*a);
    }

    void intervals_of_monotonicity() {
        double cp = critical_point();
        if (a > 0) {
            cout << "Function is decreasing on (-inf, " << cp << ") and increasing on (" << cp << ", +inf)\n";
        } 
        else if (a < 0) {
            cout << "Function is increasing on (-inf, " << cp << ") and decreasing on (" << cp << ", +inf)\n";
        } 
        else {
            cout << "Not a quadratic function\n";
        }
    }
};

int main() {
    int n;
    cout << "Enter number of quadratic equations: ";
    cin >> n;

    QuadraticEquation* arr = new QuadraticEquation[n];
    for (int i = 0; i < n; ++i) {
        double a, b, c;
        cout << "Enter coefficients a, b, c for equation " << i+1 << ": ";
        cin >> a >> b >> c;
        arr[i] = QuadraticEquation(a, b, c);
    }

    char choice;
    do {
        int index;
        cout << "Enter equation index to inspect (1-" << n << "): ";
        cin >> index;

        if (index < 1 || index > n) {
            cout << "Invalid index\n";
        } else {
            QuadraticEquation &eq = arr[index - 1];
            double x1, x2;
            bool hasRoots;
            eq.solve(x1, x2, hasRoots);

            if (hasRoots) {
                if (x1 == x2) {
                    cout << "Roots: x1 = x2 = " << x1 << "\n";
                } else {
                    cout << "Roots: x1 = " << x1 << ", x2 = " << x2 << "\n";
                }
            } else {
                cout << "No real roots.\n";
            }

            double cp = eq.critical_point();
            cout << "Critical point: " << cp << "\n";
            eq.intervals_of_monotonicity();
        }

        cout << "Do you want to check another equation? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    double maxRoot = -1e9;
    double minRoot = 1e9;
    for (int i = 0; i < n; ++i) {
        double x1, x2;
        bool hasRoots;
        arr[i].solve(x1, x2, hasRoots);
        if (hasRoots) {
            if (x1 > maxRoot) {
                maxRoot = x1;
            }
            if (x2 > maxRoot) {
                maxRoot = x2;
            }
            if (x1 < minRoot) {
                minRoot = x1;
            }
            if (x2 < minRoot) {
                minRoot = x2;
            }
        }
    }

    cout << "Maximum root among all equations = " << maxRoot << "\n";
    cout << "Minimum root among all equations = " << minRoot << "\n";

    delete[] arr;
    return 0;
}
