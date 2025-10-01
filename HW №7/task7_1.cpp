#include <iostream>
using namespace std;

int less_than_n(int n) {
    const int num[5] = {1, 2, 3, 4, 5};
    int count = 0;
    for (unsigned i = 0; i < 5; i++) {
        if (num[i] < n) {
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    cout << less_than_n(n) << "\n";
    return 0;
}
