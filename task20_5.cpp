#include <iostream>
#include <string>
#include <map>

using namespace std;

int countLetters(const string& s) {
    int cnt = 0;
    for (char c : s) {
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
            cnt++;
    }
    return cnt;
}

int main() {
    int N;
    cin >> N;
    string s;
    getline(cin, s); 

    map<int, string> result;
    int min1 = 1000000, min2 = 1000000;
    string line;

    for (int i = 0; i < N; ++i) {
        getline(cin, line);
        int letters = countLetters(line);
        if (letters < min1) {
            min2 = min1;
            if (result.count(1)) result[2] = result[1];
            min1 = letters;
            result[1] = line;
        } else if (letters < min2) {
            min2 = letters;
            result[2] = line;
        }
    }

    for (auto& p : result)
        cout << p.first << ": " << p.second << "\n";
}
