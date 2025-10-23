#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    double x;
    double y;
    cout << "enter x, y:" << "\n";
    cin >> x;
    cin >> y;
    double result = x;
    while(y > 1){
        result *= x;
        y--;
    }
    cout << dec << result << endl;
    cout << scientific << result << endl;
    return 0;
}