#include <iostream>
using namespace std;

int main() {
    float a = 1.0f;
    float eps = 1.0f;

    while (1.0f + eps != 1.0f)
        eps /= 2.0f;

    cout << "Machine zero for float: " << eps*2 << endl;
    return 0;
}
