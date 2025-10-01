#include <iostream>
using namespace std;

int main() {
    long long n;
    cout << "enter your number: ";
    cin >> n;

    int count[10] = {0};
    if(n == 0) {
        count[0] = 1;
    }

    long long temp = n;
    while(temp > 0) {
        count[temp % 10]++;
        temp /= 10;
    }

    int maxCount = 0;
    int mostFrequent = 0;
    for(int i = 0; i < 10; i++) {
        if(count[i] > maxCount) {
            maxCount = count[i];
            mostFrequent = i;
        }
    }

    cout << "most frequent digit: " << mostFrequent;
    return 0;
}
