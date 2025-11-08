#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class Rational_number {
private:
	int n;
	int m;

	static int gcd(int a, int b) {
		if (a < b) {
			a ^= b;
			b ^= a;
			a ^= b;
		}
		while (b != 0) {
			a %= b;
			a ^= b;
			b ^= a;
			a ^= b;
		}
		return a;
	}

	void simplify() {
		int g = gcd(abs(n), abs(m));
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
			cout << "Denominator cannot be zero\n";
			denominator = 1;
		}
		n = numerator;
		m = denominator;
		simplify();
	}

	int getNumerator() const {
		return n;
	}

	int getDenominator() const {
		return m;
	}

	double toDouble() const {
		return static_cast<double>(n) / m;
	}

	void input() {
		cout << "Enter numerator and denominator: ";
		cin >> n >> m;
		if (m == 0) {
			cout << "Denominator cannot be zero\n";
			m = 1;
		}
		simplify();
	}

	void output() const {
		cout << n << "/" << m;
	}

	Rational_number operator+(const Rational_number& other) const {
		return Rational_number(n * other.m + other.n * m, m * other.m);
	}

	Rational_number operator-(const Rational_number& other) const {
		return Rational_number(n * other.m - other.n * m, m * other.m);
	}

	Rational_number operator*(const Rational_number& other) const {
		return Rational_number(n * other.n, m * other.m);
	}

	Rational_number operator/(const Rational_number& other) const {
		return Rational_number(n * other.m, m * other.n);
	}

	bool operator==(const Rational_number& other) const {
		return n * other.m == other.n * m;
	}

	bool operator<(const Rational_number& other) const {
		return n * other.m < other.n * m;
	}

	bool operator>(const Rational_number& other) const {
		return n * other.m > other.n * m;
	}

	friend ostream& operator<<(ostream& os, const Rational_number& r) {
		if (r.n == 0) {
			os << "0";
		}
		else if (r.m == 1) {
			os << r.n;
		}
		else {
			os << r.n << "/" << r.m;
		}
		return os;
	}

	friend istream& operator>>(istream& is, Rational_number& r) {
		is >> r.n >> r.m;
		while (r.m == 0) {
			cout << "Denominator cannot be zero. Enter again: ";
			is >> r.m;
		}
		r.simplify();
		return is;
	}

	Rational_number absolute_value() const {
		if (n < 0) {
			return Rational_number(-n, m);
		} 
		else {
			return Rational_number(n, m);
		}
	}
};

void smallest_in_array() {
	int size;
	cout << "Enter number of elements: ";
	cin >> size;
	Rational_number* arr = new Rational_number[size];
	cout << "Enter " << size << " rational numbers (n m):\n";
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}
	Rational_number min = arr[0];
	for (int i = 1; i < size; i++) {
		if (arr[i] < min) {
			min = arr[i];
		}
	}
	cout << "Smallest element = " << min << endl;
	delete[] arr;
}


void sum_and_convergence() {
    Rational_number sum(0, 1);
    Rational_number eps(1, 10000); 
    int i = 1;
    int sign = 1;

    while (true) {
        Rational_number term(sign, i * i);
        if (term.absolute_value() < eps || i > 100000) {
            break;
        }
        sum = sum + term;
        sign = -sign;
        i++;
    }

    Rational_number result(355 * 355, 113 * 113 * 12);
    if ((sum - result).absolute_value() < eps) {
        cout << "Converges to pi*pi/12\n";
    } 
	else {
        cout << "Does not converge to pi*pi/12\n";
    }
}

int main() {
	Rational_number a, b;
	int choice;
	do {
		cout << "\n=== Menu ===\n";
		cout << "1. Enter rational numbers\n";
		cout << "2. Display rational numbers\n";
		cout << "3. Perform operations (+, -, *, /, ==, <, >)\n";
		cout << "4. Find smallest element in array\n";
		cout << "5. Calculate series sum and check convergence\n";
		cout << "0. Exit\n";
		cout << "Enter choice: ";
		cin >> choice;
		switch (choice) {
			case 1: {
				cout << "Enter first rational number (n m): ";
				cin >> a;
				cout << "Enter second rational number (n m): ";
				cin >> b;
				break;
			}
			case 2: {
				cout << "a = " << a << "\n";
				cout << "b = " << b << "\n";
				break;
			}
			case 3: {
				cout << "Enter first rational number (n m): ";
				cin >> a;
				cout << "Enter second rational number (n m): ";
				cin >> b;
				cout << "a + b = " << (a + b) << "\n";
				cout << "a - b = " << (a - b) << "\n";
				cout << "a * b = " << (a * b) << "\n";
				cout << "a / b = " << (a / b) << "\n";
				if (a == b) {
					cout << "a = b\n";
				}
				else if (a > b) {
					cout << "a > b\n";
				}
				else {
					cout << "a < b\n";
				}
				break;
			}
			case 4: {
				smallest_in_array();
				break;
			}
			case 5: {
				sum_and_convergence();
				break;
			}
			case 0: {
				cout << "Exiting\n";
				break;
			}
			default: {
				cout << "Invalid choice\n";
			}
		}
	} while (choice != 0);
	return 0;
}
