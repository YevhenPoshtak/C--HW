#include <iostream>
using namespace std;

void even_odd() {
    const int N = 50;
    int arr[N];
    int even_num = 0, odd_num = 0;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        if (arr[i] == 0) break;
        if (arr[i] % 2 == 0){
            even_num++;
        }
        else{
            odd_num++;
        }
    }
    cout << "Even numbers: " << even_num << ", Odd numbers: " << odd_num << endl;
}

int main() {
    even_odd();
    return 0;
}
