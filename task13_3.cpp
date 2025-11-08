#include <iostream>
#include <string>
using namespace std;

string removeLastLetter(const string& s) {
    string result = "";
    int i = 0;
    while (i < int(s.size())) {
        if (isspace(s[i])) {
            result += s[i];
            i++;
        } 
        else {
            int j = i;
            while (j < int(s.size()) && !isspace(s[j])) {
                j++;
            }
            if (j - i > 1) {
                result += s.substr(i, j - i - 1);
            }
            i = j;
        }
    }
    return result;
}

void modifyRemoveLastLetter(string& s) {
    s = removeLastLetter(s);
}

int main() {
    string text;
    cout << "Enter a sentence: ";
    getline(cin, text);

    string newText = removeLastLetter(text);
    cout << "New string: " << newText << endl;

    modifyRemoveLastLetter(text);
    cout << "Modified string: " << text << endl;

    return 0;
}
