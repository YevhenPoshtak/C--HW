#include<iostream>
using namespace std;

struct Vector{
    unsigned n;
    double* values;
    Vector(unsigned size){
        n = size;
        if (size > 0) {
            values = new double[size];
        }       
        else {
            values = nullptr;
        }

    }
    Vector(){
        delete[] values;
    }
};

void input(Vector& v) {
    cout << "size of vector: ";
    cin >> v.n;
    v.values = new double[v.n];
    cout << "enter elements: ";
    for (unsigned i = 0; i < v.n; i++) cin >> v.values[i];
}

void output(const Vector& v) {
    cout << "vector: [";
    for (unsigned i = 0; i < v.n; i++) {
        cout << v.values[i];
        if (i != v.n - 1) cout << ", "; 
    }
    cout << "]" << endl;
}

int main() {
    Vector v;
    input(v);
    output(v);
    return 0;
}