#include <iostream>
#include <cmath>
#include <fstream>
#include <stdexcept>

using namespace std;

class Rational_number {
private:
    int n;
    int m;

    static int gcd(int a, int b) {
        if (a < b) {
            std::swap(a, b);
        }
        while (b != 0) {
            a %= b;
            std::swap(a, b);
        }
        return a;
    }

    void simplify() {
        int g = gcd(abs(n), abs(m));
        if (g == 0) {
            return;
        }
        n /= g;
        m /= g;
        if (m < 0) {
            n = -n;
            m = -m;
        }
    }

public:
    Rational_number(int numerator = 1, int denominator = 1) {
        if (denominator == 0) {
            throw invalid_argument("Error: Denominator cannot be zero (in constructor).");
        }
        n = numerator;
        m = denominator;
        simplify();
    }

    void setNumerator(int numerator) {
        n = numerator;
        simplify();
    }

    void setDenominator(int denominator) {
        if (denominator == 0) {
            throw invalid_argument("Error: Denominator cannot be zero (in setter).");
        }
        m = denominator;
        simplify();
    }

    int getNumerator() const {
        return n;
    }

    int getDenominator() const {
        return m;
    }

    friend istream& operator>>(istream& is, Rational_number& r) {
        int tempN, tempM;
        is >> tempN >> tempM;
        if (tempM == 0) {
            throw invalid_argument("Error: Denominator cannot be zero (in input).");
        }
        r.n = tempN;
        r.m = tempM;
        r.simplify();
        return is;
    }

    friend ostream& operator<<(ostream& os, const Rational_number& r) {
        if (r.m == 1) {
            os << r.n;
        } else {
            os << r.n << "/" << r.m;
        }
        return os;
    }

    Rational_number operator-() const {
        return Rational_number(-n, m);
    }

    Rational_number operator-(const Rational_number& other) const {
        return Rational_number(n * other.m - other.n * m, m * other.m);
    }

    Rational_number operator/(const Rational_number& other) const {
        if (other.n == 0) {
            throw invalid_argument("Error: Division by zero is impossible.");
        }
        return Rational_number(n * other.m, m * other.n);
    }

    friend void writeToFile(const Rational_number& r, const string& filename);
};

void writeToFile(const Rational_number& r, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Error: Could not open file for writing.");
    }
    file << r.n << "/" << r.m;
    file.close();
}

int main() {
    try {
        cout << "--- Test 1: Data Input ---" << endl;
        Rational_number a, b;

        cout << "Enter first fraction (numerator denominator): ";
        cin >> a;

        cout << "Enter second fraction (numerator denominator): ";
        cin >> b;

        cout << "You entered: a = " << a << ", b = " << b << endl;

        cout << "\n--- Test 2: Operations ---" << endl;
        cout << "Unary minus (-a): " << -a << endl;
        cout << "Subtraction (a - b): " << (a - b) << endl;

        try {
            cout << "Division (a / b): " << (a / b) << endl;
        } catch (const exception& e) {
            cerr << "Calculation error: " << e.what() << endl;
        }

        cout << "\n--- Test 3: Write to file ---" << endl;
        string filename = "result.txt";
        writeToFile(a - b, filename);
        cout << "Subtraction result successfully written to file " << filename << endl;

    } catch (const invalid_argument& e) {
        cerr << "\nCRITICAL DATA ERROR: " << e.what() << endl;
    } catch (const runtime_error& e) {
        cerr << "\nSYSTEM ERROR: " << e.what() << endl;
    } catch (const exception& e) {
        cerr << "\nUnknown error: " << e.what() << endl;
    }

    cout << "\n--- Test 4: Attempt to create invalid fraction ---" << endl;
    try {
        Rational_number bad(5, 0);
    } catch (const exception& e) {
        cerr << "Caught expected error: " << e.what() << endl;
    }

    return 0;
}