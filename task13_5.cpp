#include <iostream>
using namespace std;

string firstKWords(const string& s, int k) {
    string result = "";
    int count = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == ' ') {
            count++;
            if (count == k) {
                break;
            }
        }
        result += s[i];
    }
    return result;
}

void modifyFirstKWords(string& s, int k) {
    s = firstKWords(s, k);
}

int main() {
    string text;
    int k;

    cout << "Enter text: ";
    getline(cin, text);

    cout << "Enter k: ";
    cin >> k;

    string first = firstKWords(text, k);
    cout << "First " << k << " words (new string): " << first << endl;

    modifyFirstKWords(text, k);
    cout << "First " << k << " words (in place): " << text << endl;

    return 0;
}
