#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    double x,y;
    cin >> x >> y;

    double arithmetic_average = (x + y) / 2;
    cout << "arithmetic average of x and y = " << scientific << arithmetic_average << endl;
    cout << "arithmetic average of x and y = " << fixed << arithmetic_average << endl;

    double harmonic_average = (2 * x * y) / (x + y);
    cout << "harmonic average of x and y = " << scientific << harmonic_average << endl;
    cout << "harmonic average of x and y = " << fixed << harmonic_average << endl;

    return 0;
}