#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

bool abs_less_than(double n, double a){
    return abs(n) < a && a > 0;
}

int main() {
    double n;
    double a;
    cout << "enter a: ";
    cin >> a; 

    ifstream fin("F.txt");      
    ofstream fout("G.txt");  

    while(fin >> n){
        if(abs_less_than(n, a)){
            fout << n << endl;
        }    
    }
    
    fin.close();
    fout.close();
    return 0;
}
