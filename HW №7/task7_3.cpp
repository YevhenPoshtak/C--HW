#include <iostream>
#include <cmath>
using namespace std;

int greater_than_e() {
    const int N = 10;
    int arr[N];  
    int count = 0;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        if (arr[i] > exp(1)) { 
            count += arr[i];
        }
    }
    return count;
}

int main() {
    cout << greater_than_e() << endl;
    return 0;
}
