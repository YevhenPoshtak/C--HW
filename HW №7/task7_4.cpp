#include <iostream>
using namespace std;

int max_element() {
    const int N = 5;
    int arr[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    int max = arr[0]; 
    for (int i = 1; i < N; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    cout << max_element() << endl;
    return 0;
}
