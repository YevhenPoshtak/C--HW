#include <iostream>
#include <string>
using namespace std;

class Rational {
private:
    int num, den;

public:
    Rational(int n = 0, int d = 1) : num(n), den(d) {
        if (den == 0) throw runtime_error("Zero denominator!");
    }

    bool operator>(const Rational& other) const {
        return (long long)num * other.den > (long long)other.num * den;
    }

    friend ostream& operator<<(ostream& os, const Rational& r) {
        return os << r.num << "/" << r.den;
    }
};

template <typename T>
T myMax(const T& a, const T& b) {
    return (a > b) ? a : b;
}

int main() {
    cout << myMax(5, 10) << endl;             
    cout << myMax(3.5, 2.1) << endl;        
    cout << myMax(string("abc"), string("xyz")) << endl;  
    cout << myMax(Rational(3,4), Rational(2,3)) << endl;   

    return 0;
}
