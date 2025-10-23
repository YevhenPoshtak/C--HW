#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    ifstream fin("input.txt");

    unsigned long long a[16384];
    int n = 0;

    while (fin >> a[n]) {
        n++;
        if (n > 16384){
            break;
        }
    }

    fin.close();

    for (int i = n - 1; i >= 0; i--){
        cout << double(a[i]) << " ";
    }

    cout << "\n";

    for (int i = n - 1; i >= 0; i--) {
        cout << fixed << setprecision(3) << sqrt(double(a[i])) << " ";
    }
    
    return 0;
}
