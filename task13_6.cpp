#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int newExtractNumbers(const string& str, double numbers[], int n, char delimiter = ' ') {
    int count = 0;
    string temp = "";
    for (int i = 0; i <= int(str.length()); i++) {
        if (i == int(str.length()) || str[i] == delimiter) {
            if (!temp.empty() && count < n) {
                double num = 0.0, frac = 0.0;
                int sign = 1, fracDiv = 1;
                int j = 0;
                if (temp[j] == '-') {
                    sign = -1;
                    j++;
                }

                while (j < int(temp.length())) {
                    if (isdigit(temp[j])) {
                        num = num * 10 + (temp[j] - '0');
                        j++;
                    }
                    else {
                        break;
                    }
                }

                if (j < int(temp.length())) {
                    if (temp[j] == '.') {
                        j++;
                        while (j < int(temp.length())) {
                            if (isdigit(temp[j])) {
                                frac = frac * 10 + (temp[j] - '0');
                                fracDiv *= 10;
                                j++;
                            }
                            else {
                                break;
                            }
                        }
                        num += frac / fracDiv;
                    }
                }
                numbers[count] = num * sign;
                count++;
                temp = "";
            }
        }
        else {
            temp += str[i];
        }
    }
    return count;
}

int modifyExtractNumbers(string& str, double numbers[], int n, char delimiter = ' ') {
    int count = newExtractNumbers(str, numbers, n, delimiter);
    str = "";
    for (int i = 0; i < count; i++) {
        str += to_string(numbers[i]);
        if (i != count - 1) {
            str += " ";
        }
    }
    return count;
}

string newFirstShortestWord(const string& sentence) {
    string shortest = "";
    int minLen = INT_MAX;
    int i = 0;
    while (i < int(sentence.length())) {
        while (i < int(sentence.length()) && sentence[i] == ' ') {
            i++;
        }
        if (i >= int(sentence.length())) {
            break;
        }
        int start = i;
        while (i < int(sentence.length()) && sentence[i] != ' ') {
            i++;
        }
        int len = i - start;
        if (len < minLen) {
            minLen = len;
            shortest = sentence.substr(start, len);
        }
    }
    return shortest;
}

void modifyFirstShortestWord(string& sentence) {
    sentence = newFirstShortestWord(sentence);
}

string newLastShortestWord(const string& sentence) {
    string shortest = "";
    int minLen = INT_MAX;
    int i = 0;
    while (i < int(sentence.length())) {
        while (i < int(sentence.length()) && sentence[i] == ' ') {
            i++;
        }
        if (i >= int(sentence.length())) {
            break;
        }
        int start = i;
        while (i < int(sentence.length()) && sentence[i] != ' ') {
            i++;
        }
        int len = i - start;
        if (len <= minLen) {
            minLen = len;
            shortest = sentence.substr(start, len);
        }
    }
    return shortest;
}

void modifyLastShortestWord(string& sentence) {
    sentence = newLastShortestWord(sentence);
}

int newAllShortestWords(const string& sentence, string results[], int maxWords) {
    string words[100];
    int count = 0;
    int minLen = INT_MAX;
    int i = 0;

    while (i < int(sentence.length())) {
        while (i < int(sentence.length()) && sentence[i] == ' ') {
            i++;
        }
        if (i >= int(sentence.length())) {
            break;
        }
        int start = i;
        while (i < int(sentence.length()) && sentence[i] != ' ') {
            i++;
        }
        int len = i - start;
        string w = sentence.substr(start, len);
        words[count] = w;
        count++;
        if (len < minLen) {
            minLen = len;
        }
    }

    int resCount = 0;
    for (int j = 0; j < count; j++) {
        if (resCount >= maxWords) {
            break;
        }
        if (int(words[j].length()) == minLen) {
            results[resCount] = words[j];
            resCount++;
        }
    }
    return resCount;
}

int modifyAllShortestWords(string& sentence, string results[], int maxWords) {
    int cnt = newAllShortestWords(sentence, results, maxWords);
    sentence = "";
    for (int i = 0; i < cnt; i++) {
        sentence += results[i];
        if (i != cnt - 1) {
            sentence += " ";
        }
    }
    return cnt;
}

int main() {
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);

    cout << "New first shortest word: " << newFirstShortestWord(sentence) << endl;
    string s1 = sentence;
    modifyFirstShortestWord(s1);
    cout << "Modified first shortest word: " << s1 << endl;

    cout << "New last shortest word: " << newLastShortestWord(sentence) << endl;
    string s2 = sentence;
    modifyLastShortestWord(s2);
    cout << "Modified last shortest word: " << s2 << endl;

    string all[10];
    int totalNew = newAllShortestWords(sentence, all, 10);
    cout << "New all shortest words: ";
    for (int i = 0; i < totalNew; i++) {
        cout << all[i] << " ";
    }
    cout << endl;

    string sentenceCopy = sentence;
    int totalModified = modifyAllShortestWords(sentenceCopy, all, 10);
    cout << "Modified all shortest words: " << sentenceCopy << endl;

    return 0;
}

