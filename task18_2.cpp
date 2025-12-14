#include <iostream>
#include <stack>
using namespace std;

template <typename T>
class Stack {
private:
    T arr[100];
    int topIndex;

public:
    Stack() : topIndex(-1) {}

    void push(const T& value) {
        if (topIndex == 99) throw runtime_error("Stack overflow");
        arr[++topIndex] = value;
    }

    T pop() {
        if (topIndex < 0) throw runtime_error("Stack empty");
        return arr[topIndex--];
    }

    bool empty() const {
        return topIndex < 0;
    }
};

void readArray(int* outArr, int& outSize) {
    outSize = 0;
    int x;
    while (true) {
        cin >> x;
        if (x == 0) break;
        outArr[outSize++] = x;
    }
}

int main() {
    int a[100];
    int n;

    cout << "Enter numbers (0 ends input): ";
    readArray(a, n);

    stack<int> stlStack;
    for (int i = 0; i < n; i++) stlStack.push(a[i]);

    cout << "Popping from std::stack: ";
    while (!stlStack.empty()) {
        cout << stlStack.top() << " ";
        stlStack.pop();
    }
    cout << endl;

    Stack<int> myStack;
    for (int i = 0; i < n; i++) myStack.push(a[i]);

    cout << "Popping from custom Stack: ";
    while (!myStack.empty()) {
        cout << myStack.pop() << " ";
    }
    cout << endl;

    return 0;
} 
