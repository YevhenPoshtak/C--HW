#include <iostream>
#include <numeric>
using namespace std;

typedef struct {
    int numerator;            
    unsigned denominator; 
} Rational;

void simplify(Rational &r) {
    int g = gcd(r.numerator, int(r.denominator));
    r.numerator /= g;
    r.denominator /= g;
}

Rational add(Rational a, Rational b) {
    Rational res;
    res.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
    res.denominator = a.denominator * b.denominator;
    simplify(res);
    return res;
}

Rational multiply(Rational a, Rational b) {
    Rational res;
    res.numerator = a.numerator * b.numerator;
    res.denominator = a.denominator * b.denominator;
    simplify(res);
    return res;
}

int compare(Rational a, Rational b) {
    if (a.numerator * b.denominator < b.numerator * a.denominator) {
        return -1;
    }
    if (a.numerator * b.denominator > b.numerator * a.denominator){
        return 1;
    }
    return 0;
}

void output(Rational r) {
    cout << r.numerator << "/" << r.denominator;
}

int main() {
    Rational r1, r2;
    cout << "Enter numerator and denomirator of first fraction: ";
    cin >> r1.numerator >> r1.denominator;
    cout << "Enter numerator and denomirator of first fraction: ";
    cin >> r2.numerator >> r2.denominator;
    cout << "r1 = "; 
    output(r1); 
    cout << endl;
    cout << "r2 = "; 
    output(r2); 
    cout << endl;
    cout << "Sum = "; 
    output(add(r1, r2)); 
    cout << endl;
    cout << "Product = "; 
    output(multiply(r1, r2)); 
    cout << endl;
    if (compare(r1, r2) < 0) {
        cout << "r1 < r2" << endl;
    }
    else if (compare(r1, r2) > 0){ 
        cout << "r1 > r2" << endl;
    }
    else{
        cout << "r1 = r2" << endl;
    }
    return 0;
}
