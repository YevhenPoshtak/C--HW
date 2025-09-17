#include <iostream>
using namespace std;

unsigned list() {
    int n;
    cout << "enter amount of numbers: ";
    cin >> n;

    int* numbers = new int[n];

    cout << "enter " << n << " numbers: ";
    for (unsigned i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    unsigned count = 0;
    for (unsigned i = 1; i < n - 1; i++) {
        if (numbers[i] > numbers[i - 1] && numbers[i] > numbers[i + 1]) {
            count++;
        }
    }
    delete[] numbers;
    return count;
}

int main() {
    unsigned result = list();
    cout << "number of local maximums: " << result << endl;
    return 0;
}
