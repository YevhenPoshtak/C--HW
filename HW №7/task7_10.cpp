#include <iostream>
using namespace std;

int main() {
    unsigned n;
    cout << "Enter n: ";
    cin >> n;
    int arr[1000];
    cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int min_val = arr[0];
    for (int i = 1; i < n; i++) {
        int val = (i + 1) * arr[i];
        if (val < min_val) {
            min_val = val;
        }
    }
    cout << "Smallest number = " << min_val << endl;
    return 0;
}
