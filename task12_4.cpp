#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main() {
    unsigned n;
    cout << "Enter n: ";
    cin >> n;

    int* m = new int[n];
    cout << "Enter " << n << " integers (m_i): ";
    for (unsigned i = 0; i < n; i++) {
        cin >> m[i];
    }

    ifstream fin("F.txt");
    if (!fin.is_open()) {
        cerr << "Error: cannot open input.txt" << endl;
        delete[] m;
        return 1;
    }

    double* x = new double[n];
    for (unsigned i = 0; i < n; i++) {
        if (!(fin >> x[i])) {
            cerr << "Error: incorrect or missing data in input.txt" << endl;
            delete[] m;
            delete[] x;
            fin.close();
            return 1;
        }
    }
    fin.close();

    ofstream fout("G.txt");
    if (!fout.is_open()) {
        cerr << "Error: cannot open output.txt" << endl;
        delete[] m;
        delete[] x;
        return 1;
    }

    fout << "Results (x_i ^ m_i): ";
    for (unsigned i = 0; i < n; i++) {
        fout << pow(x[i], m[i]) << " ";
    }

    fout.close();
    
    delete[] m;
    delete[] x;

    return 0;
}
