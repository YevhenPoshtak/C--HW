#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main(){
    double x;
    double y;
    cout << "enter x, y:" << "\n";
    cin >> x;
    cin >> y;

    cout << dec << pow(x,y) << endl;
    cout << scientific << pow(x,y) << endl;
    return 0;
}
