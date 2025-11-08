#include <iostream>
#include <string>
using namespace std;

string removeBetweenDots(const string& s) {
    int first = -1;
    int last = -1;

    for (int i = 0; i < int(s.size()); i++) {
        if (s[i] == '.') {
            first = i;
            break;
        }
    }
    for (int i = int(s.size()) - 1; i >= 0; i--) {
        if (s[i] == '.') {
            last = i;
            break;
        }
    }

    if (first == -1) { 
        int start = 0;
        while (start < int(s.size()) && s[start] == ' ') {
            start++;
        }
        if (start >= int(s.size())) {
            return "";
        }
        return s.substr(start);
    }

    if (first == last) {
        return s.substr(last + 1);
    }

    return s.substr(0, first + 1) + s.substr(last);
}

void modifyRemoveBetweenDots(string& s) {
    s = removeBetweenDots(s);
}

int main() {
    string text;
    cout << "Enter a line: ";
    getline(cin, text);

    string result = removeBetweenDots(text);
    cout << "New result: " << result << endl;

    modifyRemoveBetweenDots(text);
    cout << "Modified result: " << text << endl;

    return 0;
}
