#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

bool isAlphaNum(char c) {
    return (c >= '0' && c <= '9') ||
           (c >= 'a' && c <= 'z') ||
           (c >= 'A' && c <= 'Z');
}

bool isWordChar(char c) {
    return isAlphaNum(c) || c == '\'' || c == '-';
}

char toLower(char c) {
    if (c >= 'A' && c <= 'Z') return c - 'A' + 'a';
    return c;
}

int main() {
    ifstream file("text.txt");
    if (!file) {
        cerr << "Failed to open file\n";
        return 1;
    }

    map<string, int> wordCount;
    string word;

    while (file >> word) {
        for (size_t i = 0; i < word.size(); ++i) {
            word[i] = toLower(word[i]);
        }

        size_t start = 0;
        while (start < word.size() && !isAlphaNum(word[start])) {
            ++start;
        }

        size_t end = word.size();
        while (end > start && !isAlphaNum(word[end - 1])) {
            --end;
        }

        string cleanWord;
        for (size_t i = start; i < end; ++i) {
            if (isWordChar(word[i])) {
                cleanWord += word[i];
            }
        }

        if (!cleanWord.empty()) {
            wordCount[cleanWord]++;
        }
    }

    for (const auto& pair : wordCount) {
        cout << pair.first << ": " << pair.second << '\n';
    }

    return 0;
}
