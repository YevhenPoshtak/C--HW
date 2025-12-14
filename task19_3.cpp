#include <iostream>
#include <list>
#include <cmath>

using namespace std;

int main() {
    list<int> poly;
    
    cout << "Enter polynomial coefficients (enter -999999 to finish):\n";
    int coef;
    while (cin >> coef && coef != -999999) {
        poly.push_back(coef);
    }
    
    cout << "Polynomial coefficients: ";
    for (auto it = poly.begin(); it != poly.end(); ++it) {
        cout << *it << " ";
    }
    cout << "\n";
    
    int choice;
    do {
        cout << "\n1. Add coefficient\n";
        cout << "2. Remove coefficient\n";
        cout << "3. Calculate value\n";
        cout << "4. Display polynomial\n";
        cout << "0. Exit\n";
        cout << "Choose option: ";
        cin >> choice;
        
        if (choice == 1) {
            cout << "Enter coefficient: ";
            cin >> coef;
            poly.push_back(coef);
            cout << "Coefficient added\n";
        } else if (choice == 2) {
            if (!poly.empty()) {
                poly.pop_back();
                cout << "Last coefficient removed\n";
            } else {
                cout << "Polynomial is empty\n";
            }
        } else if (choice == 3) {
            double x;
            cout << "Enter x: ";
            cin >> x;
            double result = 0;
            double power = 1;
            for (auto it = poly.rbegin(); it != poly.rend(); ++it) {
                result += (*it) * power;
                power *= x;
            }
            cout << "P(x) = " << result << "\n";
        } else if (choice == 4) {
            cout << "Polynomial coefficients: ";
            for (auto it = poly.begin(); it != poly.end(); ++it) {
                cout << *it << " ";
            }
            cout << "\n";
        }
    } while (choice != 0);
    
    return 0;
}