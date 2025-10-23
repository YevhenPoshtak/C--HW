#include <iostream>
#include <fstream>
using namespace std;

bool checkEqualPosNeg(const char* filename) {
    ifstream inFile(filename);

    int num;
    int positive_num = 0;
    int negative_num = 0;

    while (inFile >> num) {
        if (num > 0) {
            positive_num++;
        } 
        else if (num < 0) {
            negative_num++;
        }
    }
    inFile.close();

    if (positive_num != negative_num) {
        cout << "Number of positive and negative numbers aren't equal\n";
        return false;
    }
    return true;
}

int copyToAuxFile(const char* src, const char* aux) {
    ifstream f(src);
    ofstream h(aux);

    int num;
    int n = 0;
    while (f >> num && n < 10000) {
        h << num << " ";
        n++;
    }
    f.close();
    h.close();
    return n;
}

int readFile(const char* fname, int arr[]) {
    ifstream f(fname);
    int n = 0;
    int num;
    while (f >> num && n < 10000) {
        arr[n++] = num;
    }
    f.close();
    return n;
}

void writeFile(const char* fname, int arr[], int n) {
    ofstream f(fname);
    for (int i = 0; i < n; i++) {
        f << arr[i] << " ";
    }
    f.close();
}

void rearrangePosNeg(int arr[], int n, const char* gfile) {
    int temp[10000];
    int idx = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            temp[idx++] = arr[i];
        }
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            temp[idx++] = arr[i];
        }
    }

    writeFile(gfile, temp, idx);
}


int main() {
    const char* F = "F.txt";
    const char* H = "H.txt"; 
    const char* G = "G.txt";

    if (!checkEqualPosNeg(F)) {
        return 0;
    }

    int n = copyToAuxFile(F, H);

    int arr[10000];
    n = readFile(H, arr);
    rearrangePosNeg(arr, n, G);

    return 0;
}
