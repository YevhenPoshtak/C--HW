#include <iostream>
using namespace std;

double* generateVector(unsigned n) {
    double* v = new double[n]; 
    cout << "enter " << n << " coordinates: ";
    for (unsigned i = 0; i < n; i++) {
        cin >> v[i];
    }
    return v;
}

void deleteVector(double* v) {
    delete[] v;
}

double* subtractVectors(const double* v1, const double* v2, unsigned n) {
    double* result = new double[n];
    for (unsigned i = 0; i < n; i++) {
        result[i] = v1[i] - v2[i];
    }
    return result;
}

void outputVector(const double* v, unsigned n) {
    for (unsigned i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    unsigned n;
    cout << "enter dimension of vectors: ";
    cin >> n;
    double* v1 = generateVector(n);
    double* v2 = generateVector(n);
    double* sub = subtractVectors(v1, v2, n);
    cout << "difference of vectors: ";
    outputVector(sub, n);
    deleteVector(v1);
    deleteVector(v2);
    deleteVector(sub);
    return 0;
}
