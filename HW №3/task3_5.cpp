#include <iostream>
using namespace std;

void task3_5(double x, double y){
    int min_num, max_num;
    if(x>y){
        max_num = x;
        min_num = y;
    }
    else{
        max_num = y;
        min_num = x;
    }
    cout << "Minimum: " << min_num << endl;
    cout << "Maximum: " << max_num << endl;
}

int main() {
    double x, y;
    cin >> x >> y;
    task3_5(x, y);
    return 0;
}
