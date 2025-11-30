#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class InvalidSymbolError : public exception {
private:
    string message;
public:
    InvalidSymbolError(char c, int base) {
        message = "Invalid symbol '" + string(1, c) + "' for base " + to_string(base);
    }

    const char* what() const noexcept override {
        return message.c_str();
    }
};

int getDigitFromChar(char c, int base) {
    int value = -1;

    if (c >= '0' && c <= '9') {
        value = c - '0';
    } else if (c >= 'A' && c <= 'F') {
        value = 10 + (c - 'A');
    } else if (c >= 'a' && c <= 'f') {
        value = 10 + (c - 'a');
    }

    if (value < 0 || value >= base) {
        throw InvalidSymbolError(c, base);
    }

    return value;
}

unsigned long long convertStringToNumber(const string& str, int base) {
    unsigned long long result = 0;
    for (char c : str) {
        result = result * base + getDigitFromChar(c, base);
    }
    return result;
}

int main() {
    try {
        string numberStr = "1011";
        int base = 2;
        cout << "Converting " << numberStr << " (base " << base << ") to decimal: " 
             << convertStringToNumber(numberStr, base) << endl;

        numberStr = "FF";
        base = 16;
        cout << "Converting " << numberStr << " (base " << base << ") to decimal: " 
             << convertStringToNumber(numberStr, base) << endl;

        numberStr = "12A";
        base = 10;
        cout << "Converting " << numberStr << " (base " << base << ") to decimal..." << endl;
        cout << convertStringToNumber(numberStr, base) << endl;

    } catch (const exception& e) {
        cerr << "Exception occurred: " << e.what() << endl;
    }

    return 0;
}