#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream fin("text.txt");
    string text, result, word, prev;
    char c;

    while (fin.get(c)){
        text += c;
    }
    fin.close();

    for (int i = 0; true; i++) {
        if (text[i] == ' ' || text[i] == '\0') {
            if (prev == "die" || prev == "der" || prev == "das") {
                if (word[0] >= 'a' && word[0] <= 'z')
                    word[0] -= 32;
            }

            if (!result.empty()){
                result += ' ';
            }

            result += word;
            prev = word;
            word = "";

            if (text[i] == '\0'){
                break;
            }
        } 
        else {
            word += text[i];
        }
    }

    ofstream fout("data.txt", ios::out);
    fout << result;
    fout.close();
}
