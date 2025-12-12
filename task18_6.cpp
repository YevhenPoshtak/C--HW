#include <iostream>
#include <stdexcept>
#include <cmath>
#include <string>
#include <type_traits>
#include <limits>
#include <numeric>

using namespace std;

template <typename N, typename D>
class RationalNumber {
private:
    N numerator;
    D denominator;

    template<typename T>
    T gcd(T a, T b) {
        if constexpr (is_integral_v<T>) {
            while (b != 0) {
                T temp = b;
                b = a % b;
                a = temp;
            }
            return a < 0 ? -a : a;
        }
        return 1;
    }

    void reduce() {
        if (denominator == 0) throw runtime_error("Denominator cannot be zero");
        
        if constexpr (is_integral_v<N> && is_integral_v<D>) {
            N g = gcd<N>(numerator, denominator);
            numerator /= g;
            denominator /= g;
            if (denominator < 0) {
                numerator = -numerator;
                denominator = -denominator;
            }
        }
    }

public:
    RationalNumber(N num = 0, D denom = 1) : numerator(num), denominator(denom) {
        reduce();
    }

    N getNumerator() const { return numerator; }
    D getDenominator() const { return denominator; }

    RationalNumber operator+(const RationalNumber& r) const {
        return RationalNumber(numerator * r.denominator + r.numerator * denominator,
                              denominator * r.denominator);
    }

    RationalNumber operator-(const RationalNumber& r) const {
        return RationalNumber(numerator * r.denominator - r.numerator * denominator,
                              denominator * r.denominator);
    }

    RationalNumber operator*(const RationalNumber& r) const {
        return RationalNumber(numerator * r.numerator, denominator * r.denominator);
    }

    RationalNumber operator/(const RationalNumber& r) const {
        if (r.numerator == 0) throw runtime_error("Division by zero");
        return RationalNumber(numerator * r.denominator, denominator * r.numerator);
    }

    RationalNumber operator%(const RationalNumber& r) const {
        if (r.numerator == 0) throw runtime_error("Division by zero");
        RationalNumber q = *this / r;
        N intPart = q.numerator / q.denominator;
        return *this - (RationalNumber(intPart, 1) * r);
    }

    bool operator==(const RationalNumber& r) const { 
        return numerator * r.denominator == r.numerator * denominator; 
    }
    
    bool operator!=(const RationalNumber& r) const { 
        return !(*this == r); 
    }
    
    bool operator<(const RationalNumber& r) const { 
        return numerator * r.denominator < r.numerator * denominator; 
    }
    
    bool operator<=(const RationalNumber& r) const { 
        return *this < r || *this == r; 
    }
    
    bool operator>(const RationalNumber& r) const { 
        return !(*this <= r); 
    }
    
    bool operator>=(const RationalNumber& r) const { 
        return !(*this < r); 
    }

    friend ostream& operator<<(ostream& os, const RationalNumber& r) {
        return os << r.numerator << "/" << r.denominator;
    }

    friend istream& operator>>(istream& is, RationalNumber& r) {
        N n;
        D d;
        char slash;
        is >> n >> slash >> d;
        if (is.fail() || slash != '/') {
            is.setstate(ios::failbit);
            cout << "Invalid input! Expected format: number/number" << endl;
        } else {
            r = RationalNumber(n, d);
        }
        return is;
    }
};

template <>
class RationalNumber<string, string> {
private:
    string numerator;
    string denominator;

public:
    RationalNumber(string n = "0", string d = "1") : numerator(n), denominator(d) {}

    string getNumerator() const { return numerator; }
    string getDenominator() const { return denominator; }

    RationalNumber operator+(const RationalNumber& r) const {
        string newNum = numerator + r.numerator;
        string newDen = denominator + r.denominator;
        return RationalNumber(newNum, newDen);
    }

    RationalNumber operator-(const RationalNumber&) const {
        throw runtime_error("Subtraction not supported for string");
    }
    
    RationalNumber operator*(const RationalNumber&) const {
        throw runtime_error("Multiplication not supported for string");
    }
    
    RationalNumber operator/(const RationalNumber&) const {
        throw runtime_error("Division not supported for string");
    }
    
    RationalNumber operator%(const RationalNumber&) const {
        throw runtime_error("Modulo not supported for string");
    }

    bool operator==(const RationalNumber& r) const { 
        return numerator == r.numerator && denominator == r.denominator; 
    }
    
    bool operator!=(const RationalNumber& r) const { 
        return !(*this == r); 
    }
    
    bool operator<(const RationalNumber& r) const { 
        return (numerator + "/" + denominator) < (r.numerator + "/" + r.denominator); 
    }
    
    bool operator<=(const RationalNumber& r) const { 
        return *this < r || *this == r; 
    }
    
    bool operator>(const RationalNumber& r) const { 
        return !(*this <= r); 
    }
    
    bool operator>=(const RationalNumber& r) const { 
        return !(*this < r); 
    }

    friend ostream& operator<<(ostream& os, const RationalNumber& r) {
        return os << r.numerator << "/" << r.denominator;
    }

    friend istream& operator>>(istream& is, RationalNumber& r) {
        string line;
        if (!getline(is, line)) {
            return is;
        }
        size_t slashPos = line.find('/');

        if (slashPos == string::npos) {
            is.setstate(ios::failbit);
            cout << "Invalid input! Expected format: string/string" << endl;
        } else {
            string n = line.substr(0, slashPos);
            string d = line.substr(slashPos + 1);
            r = RationalNumber(n, d);
        }
        return is;
    }
};

int main() {
    cout << "=== INTEGER RATIONAL NUMBERS ===" << endl;
    RationalNumber<int, int> r1(3, 4), r2(5, 6);
    
    cout << "r1 = " << r1 << endl;
    cout << "r2 = " << r2 << endl;
    cout << "r1.getNumerator() = " << r1.getNumerator() << endl;
    cout << "r1.getDenominator() = " << r1.getDenominator() << endl;
    
    RationalNumber<int, int> r_reduced(10, -15);
    cout << "RationalNumber(10, -15) (reduced) = " << r_reduced << endl;
    
    cout << "\nArithmetic operations:" << endl;
    cout << "r1 + r2 = " << (r1 + r2) << endl;
    cout << "r1 - r2 = " << (r1 - r2) << endl;
    cout << "r1 * r2 = " << (r1 * r2) << endl;
    cout << "r1 / r2 = " << (r1 / r2) << endl;
    
    RationalNumber<int, int> r_mod_a(10, 3);
    RationalNumber<int, int> r_mod_b(3, 2);
    cout << "(" << r_mod_a << ") % (" << r_mod_b << ") = " << (r_mod_a % r_mod_b) << endl;
    
    cout << "\nComparison operations:" << endl;
    cout << "r1 == r2: " << (r1 == r2) << endl;
    cout << "r1 != r2: " << (r1 != r2) << endl;
    cout << "r1 < r2: " << (r1 < r2) << endl;
    cout << "r1 <= r2: " << (r1 <= r2) << endl;
    cout << "r1 > r2: " << (r1 > r2) << endl;
    cout << "r1 >= r2: " << (r1 >= r2) << endl;
    
    cout << "\nInput/Output operations (Integer):" << endl;
    cout << "Enter rational number (format: n/d, e.g., 7/5): ";
    RationalNumber<int, int> r3;
    cin >> r3;

    if (cin.fail()) {
        cin.clear();
        cout << "Invalid input! Failed to read integer rational number. Using default 0/1" << endl;
    } else {
        cout << "You entered: " << r3 << endl;
    }

    if (cin.fail()) {
        cin.clear();
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    cout << "\n=== STRING RATIONAL NUMBERS ===" << endl;
    RationalNumber<string, string> s1("abc", "def");
    RationalNumber<string, string> s2("xyz", "123");
    
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s1.getNumerator() = " << s1.getNumerator() << endl;
    cout << "s1.getDenominator() = " << s1.getDenominator() << endl;
    
    cout << "\nArithmetic operations:" << endl;
    cout << "s1 + s2 (concatenation) = " << (s1 + s2) << endl; 
    
    try {
        cout << "s1 - s2: ";
        auto x = s1 - s2;
    } catch (const exception& e) {
        cout << "Error - " << e.what() << endl;
    }
    
    try {
        cout << "s1 * s2: ";
        auto x = s1 * s2;
    } catch (const exception& e) {
        cout << "Error - " << e.what() << endl;
    }
    
    try {
        cout << "s1 / s2: ";
        auto x = s1 / s2;
    } catch (const exception& e) {
        cout << "Error - " << e.what() << endl;
    }
    
    try {
        cout << "s1 % s2: ";
        auto x = s1 % s2;
    } catch (const exception& e) {
        cout << "Error - " << e.what() << endl;
    }
    
    cout << "\nComparison operations:" << endl;
    RationalNumber<string, string> s4("abc", "def");
    
    cout << "s1 == s2: " << (s1 == s2) << endl;
    cout << "s1 == s4: " << (s1 == s4) << endl;
    cout << "s1 != s2: " << (s1 != s2) << endl;
    cout << "s1 < s2: " << (s1 < s2) << endl; 
    cout << "s1 <= s2: " << (s1 <= s2) << endl;
    cout << "s1 > s2: " << (s1 > s2) << endl;
    cout << "s1 >= s2: " << (s1 >= s2) << endl;
    
    cout << "\nInput/Output operations (String):" << endl;
    cout << "Enter string rational (format: str1/str2, e.g., A/B): ";
    RationalNumber<string, string> s3;
    cin >> s3;
    if (cin.fail()) {
        cin.clear();
        cout << "Failed to read string rational. Using default 0/1" << endl;
    } else {
        cout << "You entered: " << s3 << endl;
    }

    return 0;
}
