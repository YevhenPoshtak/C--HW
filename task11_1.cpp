#include <iostream>
#include <fstream>
using namespace std;

void input_array(double* arr, unsigned n) {
    for (unsigned i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void output_array(double* arr, unsigned n, const char* filename) {
    ofstream fout(filename);
    fout << "[";
    for (unsigned i = 0; i < n; i++) {
        fout << arr[i];
        if (i != n - 1) fout << ",";
    }
    fout << "]";
    fout.close();
}

void print_file(const char* filename) {
    ifstream fin(filename);
    char c;
    fin >> c; 
    cout << "[";
    bool first = true;
    double x;
    while (fin >> x) {
        if (!first) cout << ",";
        cout << x;
        first = false;
        fin >> c; 
    }
    cout << "]\n";
    fin.close();
}

int main() {
    unsigned n;
    cout << "Enter array size: ";
    cin >> n;
    double* arr = new double[n];
    cout << "Enter " << n << " numbers: ";
    input_array(arr, n);

    const char* filename = "F.txt";
    output_array(arr, n, filename);

    cout << "File content: ";
    print_file(filename);

    delete[] arr;
    return 0;
}
