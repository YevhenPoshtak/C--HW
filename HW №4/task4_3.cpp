#include<iostream>
#include<cmath>
using namespace std;

unsigned polynom1(unsigned n, unsigned  x, unsigned  y){
        unsigned  res = 1;
        for(unsigned i = n; i >=1; i--){
            res += pow(x,pow(2,i))*pow(y,i);
    }
    return res;
}
unsigned  polynom2(unsigned n, unsigned  x){
        unsigned  res = 1;
        for(unsigned i = n; i >=1; i--){
            res += pow(x,i);
    }
    return res;
}
int main(){
    unsigned n = 4;
    unsigned  x = 1;
    unsigned  y = 2;
    unsigned n1 = 3;
    unsigned  x1 = 2;
    cout << "y = " << polynom1(n,x,y) << endl;
    cout << "y = " << polynom2(n1,x1) << endl;
    return 0;
}