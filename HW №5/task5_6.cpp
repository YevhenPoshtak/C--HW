#include <cmath>

double exp_taylor(double x) {
    const double epsilon;  
    double term = 1.0;            
    double sum = term;             
    int n = 1;

    while (fabs(term) > epsilon) {
        term *= x / n;  
        sum += term;
        n++;
    }

    return sum;
}

int main(){
    const double epsilon;
    double x;
    cin >> epsilon;
    cin >> x;

    cout << exp_taylor << "\n";
    return 0; 
}
