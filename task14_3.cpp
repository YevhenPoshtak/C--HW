#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("text.txt");
    ofstream fout("reversed.txt");

    char c;
    string word = "";

    while (fin.get(c)) {
        if (c != ' ') {
            word += c;  
        } 
        
        else {
            for (int i = word.size() - 1; i >= 0; i--) {
                fout << word[i];
            }
            fout << c;  
            word = "";  
        }
    }

    for (int i = word.size() - 1; i >= 0; i--) {
        fout << word[i];
    }

    fin.close();
    fout.close();
    return 0;
}
