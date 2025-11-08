#include <iostream>
#include <string>
#include <sstream>
using namespace std;

double* newExtractNumbers(const string& s, char delimiter, int n) {
    double* result = new double[n];
    istringstream ss(s);
    string temp;
    int count = 0;

    while (getline(ss, temp, delimiter) && count < n) {
        if (!temp.empty()) {
            stringstream convert(temp);
            double val;
            convert >> val;
            result[count++] = val;
        }
    }

    for (int i = count; i < n; i++) {
        result[i] = 0;
    }
    return result;
}

void modifyExtractNumbers(const string& s, char delimiter, double* arr, int n) {
    istringstream ss(s);
    string temp;
    int count = 0;

    while (getline(ss, temp, delimiter) && count < n) {
        if (!temp.empty()) {
            stringstream convert(temp);
            double val;
            convert >> val;
            arr[count++] = val;
        }
    }

    for (int i = count; i < n; i++) {
        arr[i] = 0;
    }
}

int main() {
    string str;
    cout << "Enter numbers separated by comma: ";
    getline(cin, str);

    int n;
    cout << "Enter how many numbers to extract: ";
    cin >> n;

    double* arr1 = newExtractNumbers(str, ',', n);
    cout << "New array: ";
    for (int i = 0; i < n; i++) cout << arr1[i] << " ";
    cout << endl;
    delete[] arr1;

    double* arr2 = new double[n]; 
    modifyExtractNumbers(str, ',', arr2, n);
    cout << "Modified array: ";
    for (int i = 0; i < n; i++) cout << arr2[i] << " ";
    cout << endl;
    delete[] arr2;

    return 0;
}
