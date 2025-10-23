#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

struct Term {
    double coef;
    int deg;
};

int readPolynomial(const char* filename, Term poly[]) {
    ifstream f(filename);
    int n = 0;
    while (f >> poly[n].coef >> poly[n].deg) n++;
    f.close();
    return n;
}

void writePolynomial(const char* filename, Term poly[], int n) {
    ofstream f(filename);
    for (int i = 0; i < n; i++) {
        f << poly[i].coef << " " << poly[i].deg << "\n";
    }
    f.close();
}

int cleanPolynomial(Term poly[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (poly[i].deg == poly[j].deg) {
                poly[i].coef += poly[j].coef;
                for (int k = j; k < n - 1; k++) {
                    poly[k] = poly[k + 1];
                }
                n--; 
                j--;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (poly[i].coef == 0) {
            for (int k = i; k < n - 1; k++) {
                poly[k] = poly[k + 1];
            }
            n--; 
            i--;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (poly[i].deg < poly[j].deg) {
                Term t = poly[i];
                poly[i] = poly[j];
                poly[j] = t;
            }
        }
    }
    return n;
}

void inputPolynomial(const char* filename) {
    Term poly[100];
    int n;
    cout << "Enter number of terms: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "coef deg: ";
        cin >> poly[i].coef >> poly[i].deg;
    }
    n = cleanPolynomial(poly, n);
    writePolynomial(filename, poly, n);
}

void printPolynomial(const char* filename) {
    Term poly[100];
    int n = readPolynomial(filename, poly);
    if (n == 0) {
        cout << "0\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        if (i > 0) {
            if (poly[i].coef >= 0) {
                cout << " + ";
            } else {
                cout << " - ";
            }
        } else {
            if (poly[i].coef < 0) {
                cout << "-";
            }
        }

        double c = abs(poly[i].coef);
        if (poly[i].deg == 0) {
            cout << c;
        } else if (poly[i].deg == 1) {
            cout << c << "x";
        } else {
            cout << c << "x^" << poly[i].deg;
        }
    }
    cout << "\n";
}

double evalPolynomial(const char* filename, double x) {
    Term poly[100];
    int n = readPolynomial(filename, poly);
    double res = 0;
    for (int i = 0; i < n; i++) {
        res += poly[i].coef * pow(x, poly[i].deg);
    }
    return res;
}

void appendTerm(const char* filename) {
    Term poly[100];
    int n = readPolynomial(filename, poly);
    Term t;
    cout << "Enter coef deg to append: ";
    cin >> t.coef >> t.deg;
    poly[n++] = t;
    n = cleanPolynomial(poly, n);
    writePolynomial(filename, poly, n);
}

void replaceCoef(const char* filename) {
    Term poly[100];
    int n = readPolynomial(filename, poly);

    int deg;
    double coef;
    cout << "Enter degree to replace: ";
    cin >> deg;
    cout << "Enter new coef: ";
    cin >> coef;

    bool found = false;
    for (int i = 0; i < n; i++) {
        if (poly[i].deg == deg) {
            poly[i].coef = coef;
            found = true;
            break;
        }
    }
    if (!found) {
        poly[n++] = {coef, deg};
    }
    n = cleanPolynomial(poly, n);
    writePolynomial(filename, poly, n);
}

int main() {
    const char* file = "F.txt";

    inputPolynomial(file);
    cout << "Polynomial: ";
    printPolynomial(file);

    double x;
    cout << "Enter x: ";
    cin >> x;
    cout << "Value at x = " << evalPolynomial(file, x) << "\n";

    int choice;
    cout << "\nChoose an operation:\n1. Append term\n2. Replace coefficient\nEnter choice: ";
    cin >> choice;

    switch(choice) {
        case 1: {
            appendTerm(file); 
            break;
        }
        case 2: {
            replaceCoef(file); 
            break;
        }
        default: {
            cout << "Invalid choice\n"; 
            break;
        }
    }

    cout << "Updated Polynomial: ";
    printPolynomial(file);

    return 0;
}
