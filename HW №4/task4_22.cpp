#include <iostream>
using namespace std;

unsigned list() {
    int n;
    cout << "enter amount of numbers: ";
    cin >> n;

    int prev, curr, next;
    cout << "enter " << n << " numbers: ";
    cin >> prev >> curr; 

    unsigned count = 0;

    for (int i = 2; i < n; i++) {
        cin >> next; 

        if (curr > prev && curr > next) {
            count++;
        }

        prev = curr;
        curr = next;
    }

    return count;
}

int main() {
    unsigned result = list();
    cout << "number of local maximums: " << result << endl;
    return 0;
}
