#include <iostream>
#include <fstream>
using namespace std;

bool is_palindrom(int n){
    int rev = 0, orig = n;
    while (n > 0) {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    return rev == orig;
}

int main() {
    int n;
    ofstream fout("F.txt"); 
    cout << "Enter numbers (0 for end): ";
    cin >> n;
    while(n != 0){
        fout << n << " ";
        cin >> n;
    } 
    fout.close(); 

    ifstream fin("F.txt");
    ofstream foutG("G.txt");

    while (fin >> n) { 
        if (is_palindrom(n)) {
            foutG << n << " ";  
        }
    }
    fin.close();
    foutG.close();
    return 0;
}
