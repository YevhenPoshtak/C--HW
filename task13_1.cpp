#include <iostream>
#include <string>
using namespace std;

string extractBetweenColonAndComma(const string& s) {
    int colon = s.find(':');
    if (colon == -1) {
        return s; 
    }

    int comma = s.find(',', colon + 1);
    if (comma == -1) {
        return s.substr(colon + 1); 
    }

    return s.substr(colon + 1, comma - colon - 1);
}

void modifyExtractBetweenColonAndComma(string& s) {
    s = extractBetweenColonAndComma(s);
}

int main() {
    string text;
    cout << "Enter a line: ";
    getline(cin, text);

    string result = extractBetweenColonAndComma(text);
    cout << "New string: " << result << endl;

    modifyExtractBetweenColonAndComma(text);
    cout << "Modified string: " << text << endl;
}
