#include <iostream>
#include <cmath>
using namespace std;

double perimeter(double a,double b,double c){
    return a+b+c;
}
double area(double a,double b,double c){
    double p = perimeter(a, b, c) / 2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}
int main(){
    double a,b,c;
    cin >> a >> b >> c;
    cout << "area of triangle = " << area(a,b,c) << endl;
    return 0;
}