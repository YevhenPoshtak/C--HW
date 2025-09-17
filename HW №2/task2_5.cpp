#include <iostream>
#include <cmath>
using namespace std;

double Rosenblock2d(double x, double y){
    return 100*pow((pow(x,2) - y),2) + pow((x-1),2);
}

int main(){
    double x,y,z,a,b,c;
    cin >> x >> y >> z >> a >> b >> c ;
    cout << "result = " << Rosenblock2d(x,y) << endl;
    cout << "result = " << Rosenblock2d(z,a) << endl;
    cout << "result = " << Rosenblock2d(b,c) << endl;
    return 0;
}