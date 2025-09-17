#include <iostream>
#include<cmath>

using namespace std;
double fact(int n){
    unsigned res = 1;
    for(unsigned i = 1; i <= n; i++){
        res *=i;
    }
    return res;
}

double exp(double x, int n) {
    double sum = 1.0; 
    for (int i = 1; i <= n; i++) {
        sum += pow(x, i) / fact(i);
    }
    return sum;
}

int main(){
    double x;
    int n;
    cin >> x >> n;
    cout << exp(x,n) << endl;
    return 0;
}