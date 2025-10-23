#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

struct TPair {
    unsigned key;
    char data[10];
};

bool searchOrdered(const char* filename, unsigned key, TPair &res) {
    ifstream fin(filename);
    if (!fin) return false;

    TPair tmp;
    while (fin >> tmp.key >> tmp.data) {
        if (tmp.key == key) {
            res = tmp;
            return true;
        }
        if (tmp.key > key) break;
    }
    return false;
}

bool deleteOrdered(const char* filename, unsigned key) {
    ifstream fin(filename);
    if (!fin) return false;

    ofstream fout("temp.txt");
    if (!fout) return false;

    TPair tmp;
    bool found = false;

    while (fin >> tmp.key >> tmp.data) {
        if (tmp.key == key) {
            found = true;
            continue;
        }
        fout << tmp.key << " " << tmp.data << "\n";

        if (tmp.key > key && !found) {
            while (fin >> tmp.key >> tmp.data) {
                fout << tmp.key << " " << tmp.data << "\n";
            }
            break;
        }
    }

    fin.close();
    fout.close();
    rename("temp.txt", filename);
    return found;
}

bool deleteUnordered(const char* filename, unsigned key) {
    ifstream fin(filename);
    if (!fin) return false;

    ofstream fout("temp.txt");
    if (!fout) return false;

    TPair tmp;
    bool found = false;

    while (fin >> tmp.key >> tmp.data) {
        if (tmp.key == key) {
            found = true;
            continue;
        }
        fout << tmp.key << " " << tmp.data << "\n";
    }

    fin.close();
    fout.close();
    rename("temp.txt", filename);
    return found;
}

int main() {
    const char* fname = "F.txt";
    TPair res;
    unsigned key;
    int choice;

    while (true) {
        cout << "\n--- MENU ---\n";
        cout << "1. Search in ordered file\n";
        cout << "2. Delete from ordered file\n";
        cout << "3. Delete from unordered file\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key to search: ";
                cin >> key;
                if (searchOrdered(fname, key, res))
                    cout << "Found key " << res.key << " with data: " << res.data << endl;
                else
                    cout << "Key not found.\n";
                break;
            case 2:
                cout << "Enter key to delete (ordered): ";
                cin >> key;
                if (deleteOrdered(fname, key))
                    cout << "Key deleted from ordered file.\n";
                else
                    cout << "Key not found in ordered file.\n";
                break;
            case 3:
                cout << "Enter key to delete (unordered): ";
                cin >> key;
                if (deleteUnordered(fname, key))
                    cout << "Key deleted from unordered file.\n";
                else
                    cout << "Key not found in unordered file.\n";
                break;
            case 0:
                return 0;
            default:
                cout << "Invalid choice.\n";
        }
    }
}
