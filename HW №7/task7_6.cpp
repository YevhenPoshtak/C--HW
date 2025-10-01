#include <iostream>
using namespace std;
const int MAX_LEN = 20;

void input_vector(double arr[], int n) {
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void output_vector(double arr[], int n) {
    cout << "(";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i != n - 1) cout << ", ";
    }
    cout << ")" << endl;
}

void sum_vectors(double a[], double b[], double res[], int n) {
    for (int i = 0; i < n; i++) {
        res[i] = a[i] + b[i];
    }
}

double scalar_product(double a[], double b[], int n) {
    double prod = 0;
    for (int i = 0; i < n; i++) {
        prod += a[i] * b[i];
    }
    return prod;
}

int main() {
    int n;
    cout << "Enter number between 1 and 20: ";
    cin >> n;

    if (n <= 0 || n > MAX_LEN) {
        cout << "wrong number" << endl;
    }

    double v1[MAX_LEN], v2[MAX_LEN], res[MAX_LEN];

    cout << "enter coordinates of first vector:" << endl;
    input_vector(v1, n);

    cout << "enter coordinates of second vector:" << endl;
    input_vector(v2, n);

    cout << "first vector: ";
    output_vector(v1, n);

    cout << "second vector: ";
    output_vector(v2, n);

    sum_vectors(v1, v2, res, n);
    cout << "sum of vectors: ";
    output_vector(res, n);

    cout << "scalar product of vectors: " << scalar_product(v1, v2, n) << endl;

    return 0;
}
