#include <iostream>
using namespace std;

unsigned double_factorial(unsigned n){
    unsigned res = 1;  
    for(unsigned i = n; i > 1; i -= 2){  
        res *= i;
    }
    return res;
}

int main(){
    unsigned n;
    cout << "n = "; 
    cin >> n;
    cout << "y = " << double_factorial(n) << endl;
    return 0;
}
