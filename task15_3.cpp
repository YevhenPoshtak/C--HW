#include <iostream>
#include <fstream>
using namespace std;

class Polynom {
private:
    int N;
    double* coeffs;

public:
    Polynom(int n) : N(n) {
        coeffs = new double[N];
        for(int i = 0; i < N; i++){
            coeffs[i] = 0;
        }
    }

    Polynom(int n, double* arr) : N(n) {
        coeffs = new double[N];
        for(int i = 0; i < N; i++){
            coeffs[i] = arr[i];
        }
    }

    Polynom(const Polynom& other) : N(other.N) {
        coeffs = new double[N];
        for(int i = 0; i < N; i++){
            coeffs[i] = other.coeffs[i];
        }
    }

    ~Polynom() {
        delete[] coeffs;
    }

    void setCoeff(int index, double value) {
        if(index >= 0 && index < N){
            coeffs[index] = value;
        }
        else{
            cout << "Index out of array\n";
        }
    }

    void output() const {
        for(int i = 0; i < N; i++) {
            cout << coeffs[i];
            if(i > 0){
                cout << "*x^" << i;
            }
            if(i != N-1){
                cout << " + ";
            }
        }
        cout << endl;
    }

    Polynom& operator=(const Polynom& other) {
        if(this == &other){
            return *this; 
        }
        delete[] coeffs; 
        N = other.N;
        coeffs = new double[N];
        for(int i = 0; i < N; i++){
            coeffs[i] = other.coeffs[i];
        }
        return *this;
    }

    friend void writeToFile(const Polynom& p, const char* filename) {
        ofstream fout(filename, ios::binary);
        fout.write((char*)&p.N, sizeof(int));
        fout.write((char*)p.coeffs, sizeof(double) * p.N);
        fout.close();
    }
    friend void readFromFile(Polynom& p, const char* filename) {
        ifstream fin(filename, ios::binary);
        int n;
        fin.read((char*)&n, sizeof(int));
        delete[] p.coeffs;
        p.N = n;
        p.coeffs = new double[n];
        fin.read((char*)p.coeffs, sizeof(double) * n);
        fin.close();
    }
};

int main() {
    int n;
    cout << "Enter the number of coefficients for the polynomial: ";
    cin >> n;

    Polynom p1(n);

    for(int i = 0; i < n; i++) {
        double coeff;
        cout << "Enter coefficient for x^" << i << ": ";
        cin >> coeff;
        p1.setCoeff(i, coeff);
    }

    cout << "\nOriginal polynomial p1: ";
    p1.output();

    writeToFile(p1, "polynom.bin");
    cout << "\nPolynomial saved to file 'polynom.bin'\n";

    Polynom p2(0); 
    readFromFile(p2, "polynom.bin");
    cout << "Polynomial read from file p2: ";
    p2.output();

    Polynom p3 = p2;
    cout << "Polynomial p3 (copy of p2): ";
    p3.output();

    Polynom p4(2); 
    p4 = p1;
    cout << "Polynomial p4 (assigned from p1): ";
    p4.output();

    return 0;
}
