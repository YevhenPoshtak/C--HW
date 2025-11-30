#include <iostream>
#include <stdexcept>
#include <cmath>

using namespace std;

template <typename N, typename D>
class RationalNumber {
private:
    N numerator;
    D denominator;

    // gcd для цілих
    N gcd(N a, N b) {
        while (b != 0) {
            N temp = b;
            b = a % b;
            a = temp;
        }
        if (a < 0) {
            a = -a;
        }
        return a;
    }

    void reduceInt() {
        if (denominator == 0) {
            throw runtime_error("Denominator cannot be zero");
        }

        N g = gcd(numerator, denominator);
        numerator /= g;
        denominator /= g;

        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

    void reduceFloat() {
        if (denominator == 0) {
            throw runtime_error("Denominator cannot be zero");
        }

        const int precision = 1000000; 
        long long num = static_cast<long long>(numerator * precision);
        long long den = static_cast<long long>(denominator * precision);
        long long g = gcd(num, den);

        numerator = static_cast<N>(num / g);
        denominator = static_cast<D>(den / g);
    }

    void reduce() {
        if constexpr (std::is_integral_v<N> && std::is_integral_v<D>) {
            reduceInt();
        } else {
            reduceFloat();
        }
    }

public:
    RationalNumber(N num = 0, D denom = 1) : numerator(num), denominator(denom) {
        reduce();
    }

    N getNumerator() const { 
        return numerator; 
    }

    D getDenominator() const { 
        return denominator; 
    }

    RationalNumber operator+(const RationalNumber& rhs) const {
        return RationalNumber(numerator * rhs.denominator + rhs.numerator * denominator,
                              denominator * rhs.denominator);
    }

    RationalNumber operator-(const RationalNumber& rhs) const {
        return RationalNumber(numerator * rhs.denominator - rhs.numerator * denominator,
                              denominator * rhs.denominator);
    }

    RationalNumber operator*(const RationalNumber& rhs) const {
        return RationalNumber(numerator * rhs.numerator,
                              denominator * rhs.denominator);
    }

    RationalNumber operator/(const RationalNumber& rhs) const {
        if (rhs.numerator == 0) {
            throw runtime_error("Division by zero!");
        }
        return RationalNumber(numerator * rhs.denominator,
                              denominator * rhs.numerator);
    }

    bool operator==(const RationalNumber& rhs) const { 
        return numerator * rhs.denominator == rhs.numerator * denominator; 
    }

    bool operator!=(const RationalNumber& rhs) const { 
        return !(*this == rhs); 
    }

    bool operator<(const RationalNumber& rhs) const { 
        return numerator * rhs.denominator < rhs.numerator * denominator; 
    }

    bool operator<=(const RationalNumber& rhs) const { 
        if (*this < rhs || *this == rhs) {
            return true;
        } else {
            return false;
        }
    }

    bool operator>(const RationalNumber& rhs) const { 
        if (!(*this <= rhs)) {
            return true;
        } else {
            return false;
        }
    }

    bool operator>=(const RationalNumber& rhs) const { 
        if (!(*this < rhs)) {
            return true;
        } else {
            return false;
        }
    }

    void print() const { 
        cout << numerator << "/" << denominator; 
    }
};

int main() {
    RationalNumber<int,int> r1(3,4);
    RationalNumber<int,int> r2(5,6);

    RationalNumber<double,double> r3(1.5,2.5); 
    RationalNumber<double,double> r4(2.0,3.0);

    auto sum1 = r1 + r2;
    auto sum2 = r3 + r4;

    sum1.print(); cout << "\n"; 
    sum2.print(); cout << "\n"; 

    return 0;
}
