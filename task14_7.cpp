#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int findClosingBracket(const string& line, size_t start) {
    for (size_t i = start; i < line.size(); ++i) {
        if (line[i] == '>') {
            return i;
        }
    }
    return -1;
}

bool checkTags(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Cannot open the file" << endl;
        return false;
    }

    string openTag = "";
    string line;
    bool error = false;

    while (getline(file, line)) {
        for (size_t i = 0; i < line.size(); ++i) {
            if (line[i] == '<') {
                int j = findClosingBracket(line, i + 1);
                if (j == -1) {
                    cout << "Incorrect tag" << endl;
                    return false;
                }

                string tag = line.substr(i + 1, j - i - 1);

                if (!tag.empty() && tag[0] == '/') {
                    string closeTag = tag.substr(1);
                    if (openTag != closeTag) {
                        cout << "Mismatched tag: </" << closeTag << ">" << endl;
                        error = true;
                    } 
                    else {
                        openTag = "";
                    }
                } 
                else {
                    if (!openTag.empty()) {
                        cout << "Nested tags are not supported without stack" << endl;
                        error = true;
                    }
                    openTag = tag;
                }

                i = j;
            }
        }
    }

    if (!openTag.empty()) {
        cout << "Tag not closed: <" << openTag << ">" << endl;
        error = true;
    }

    return !error;
}

int main() {
    string filename;
    cout << "Enter the filename: ";
    cin >> filename;

    if (checkTags(filename)) {
        cout << "All tags are properly closed." << endl;
    } else {
        cout << "There are tag errors." << endl;
    }

    return 0;
}
