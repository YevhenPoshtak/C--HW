#include <iostream>
#include <string>
using namespace std;

void newFindLongestWords(const string& sentence, string result[], int& count, int& maxLength) {
    count = 0;
    maxLength = 0;
    int i = 0;

    while (i < sentence.length()) {
        while (i < sentence.length() && sentence[i] == ' ') {
            i++;
        }
        if (i >= sentence.length()) {
            break;
        }

        string word = "";
        while (i < sentence.length() && sentence[i] != ' ') {
            word += sentence[i++];
        }

        if (word.length() > maxLength) {
            maxLength = word.length();
            result[0] = word;
            count = 1;
        } 
        
        else if (word.length() == maxLength) {
            result[count++] = word;
        }
    }
}

void modifyFindLongestWords(string& sentence) {
    string longestWords[100];
    int longestCount = 0;
    int maxLength = 0;

    int i = 0;
    while (i < sentence.length()) {
        while (i < sentence.length() && sentence[i] == ' ') {
            i++;
        }
        if (i >= sentence.length()) {
            break;
        }

        string word = "";
        while (i < sentence.length() && sentence[i] != ' ') {
            word += sentence[i++];
        }

        if (word.length() > maxLength) {
            maxLength = word.length();
            longestWords[0] = word;
            longestCount = 1;
        } 
        
        else if (word.length() == maxLength) {
            longestWords[longestCount++] = word;
        }
    }

    sentence = "";
    for (int j = 0; j < longestCount; j++) {
        sentence += longestWords[j];

        if (j != longestCount - 1) {
            sentence += ", ";
        }
    }
}

int main() {
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);

    string longestWords[100];
    int count = 0, maxLength = 0;
    newFindLongestWords(sentence, longestWords, count, maxLength);

    cout << "Longest word(s) with length " << maxLength << ": ";
    for (int j = 0; j < count; j++) {
        cout << longestWords[j];
        if (j != count - 1) cout << ", ";
    }
    cout << endl;

    modifyFindLongestWords(sentence);
    cout << "Longest words (modified sentence): " << sentence << endl;

    return 0;
}
