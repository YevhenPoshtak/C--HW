#include <iostream>
using namespace std;

int main() {
    unsigned int n;
    cout << "enter n: ";
    cin >> n;

    int maxCount = 0; 
    int currentCount = 0;

    while (n > 0) {
        if (n & 1) { 
            currentCount++;
            if (currentCount > maxCount)
                maxCount = currentCount;
        } else {
            currentCount = 0; 
        }
        n >>= 1;
    }

    cout << maxCount << endl;
    return 0;
}
