#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
    float num11 = 1e-4;
    double num12 = 1e-4;
    long double num13 = 1e-4;
    cout << fixed << setprecision(2);
    cout << "float num11:" << num11 << endl;
    cout << "float num12:" << num12 << endl;
    cout << "float num13:" << num13 << endl;

    float num21 = 24.33e5;
    double num22 = 24.33e5;
    long double num23 = 24.33e5;
    cout << fixed << setprecision(2);
    cout << "float num21:" << num21 << endl;
    cout << "float num22:" << num22 << endl;
    cout << "float num23:" << num23 << endl;

    float num31 = M_PI;
    double num32 = M_PI;
    long double num33 = M_PI;
    cout << fixed << setprecision(2);
    cout << "float num31:" << num31 << endl;
    cout << "float num32:" << num32 << endl;
    cout << "float num33:" << num33 << endl;

    float num41 = M_E;
    double num42 = M_E;
    long double num43 = M_E;
    cout << fixed << setprecision(2);
    cout << "float num41:" << num41 << endl;
    cout << "float num42:" << num42 << endl;
    cout << "float num43:" << num43 << endl;


    float num51 = sqrt(5.0f);
    double num52 = sqrt(5.0);
    long double num53 = sqrt(5.0L);
    cout << fixed << setprecision(2);
    cout << "float num51:" << num51 << endl;
    cout << "float num52:" << num52 << endl;
    cout << "float num53:" << num53 << endl;

    float num61 = log(100.0f);
    double num62 = log(100.0);
    long double num63 = log(100.0L);
    cout << "float num61:" << num61 << endl;
    cout << "float num62:" << num62 << endl;
    cout << "float num63:" << num63 << endl;

    return 0;
}