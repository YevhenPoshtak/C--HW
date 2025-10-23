#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    ifstream fin("numbers.txt");

    int m = 16;
    double* arr = new double[m];
    int n = 0;
    double value;
    char c;

    while (fin >> c) {
        if (c == ';'){
            continue;
        }
        fin.putback(c);
        if (!(fin >> value)){
            break;
        }
        if (n >= m) {
            m *= 2;
            double* temp = new double[m];
            for (int i = 0; i < n; i++) temp[i] = arr[i];
            delete[] arr;
            arr = temp;
        }
        arr[n++] = value;
    }

    fin.close();

    ofstream fout("arcsin.txt");

    for (int i = 0; i < n; i++) {
        if (arr[i] >= -1 && arr[i] <= 1) {
            fout << scientific << "arcsin(" << arr[i] << ") = " << asin(arr[i]) << endl;
            fout << endl;
        }
    }

    delete[] arr;
    fout.close();
    return 0;
}
