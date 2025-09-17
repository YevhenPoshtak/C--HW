#include <iostream>
using namespace std;

int main() {
    unsigned n;
    cout << "n = ";
    cin >> n;

    cout << "n! = ";
    for (unsigned i = 1; i <= n; i++) {
        cout << i;
        if (i < n) cout << "*"; 
    }
    cout << endl;

    cout << "n! = ";
    for (int i = n; i >= 1; i--) {  
        cout << i;
        if (i > 1) cout << "*"; 
    }
    cout << endl;

    return 0;
}
