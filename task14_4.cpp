#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream fin("text.txt");
    string text;
    char c;

    while (fin.get(c)) {
        text += c;
    }
    fin.close();

    int count = 0;

    for (int i = 0; i < text.size(); i++) {
        if (text[i] == '<' && text[i + 1] == 't' && text[i + 2] == 'd' && text[i + 3] == '>') {
            count++;
            continue;
        }

        if (text[i] == '<' && text[i + 1] == '/' && text[i + 2] == 't' && text[i + 3] == 'd' && text[i + 4] == '>') {
            count--;
            if (count < 0) {
                cout << "Error";
                return 0;
            }
        }
    }

    if (count == 0) {
        cout << "Tags are correct\n";
    } else {
        cout << "Not all tags are closed\n";
    }

    return 0;
}
