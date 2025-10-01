#include <iostream>
#include <cmath>
using namespace std;

int inputArray(int arr[], int max = 100) {
    int n = 0, x;
    while (n < max && cin >> x && x != 0) {
        arr[n++] = x;
    }
    return n;
}

void SquaresAndCubes(int arr[], int n, int squares, int cubes) {
    squares = 0;
    cubes = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0) {
            int s = int(sqrt(arr[i] + 0.5)); 
            if (s * s == arr[i]){ 
                squares++;
            }
        }
            int c = int(round(cbrt(arr[i])));
            if (c * c * c == arr[i]){ 
                cubes++;
            }
    }
}

int main() {
    int arr[100], n = 0, x;
    while (cin >> x && x != 0 && n < 100) {
        arr[n++] = x;
    }
    int squares, cubes;
    SquaresAndCubes(arr, n, squares, cubes);
    cout << "Squares: " << squares << endl;
    cout << "Cubes: " << cubes << endl;
    return 0;
}
