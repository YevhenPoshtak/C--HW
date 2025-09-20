#include <iostream>
#include <cstdint>
using namespace std;

uint16_t mult_task4(uint8_t x, uint8_t y) {
    return x * y;
}

void task3_4() { 
    int temp_x, temp_y;  
    cout << "x,y: ";
    cin >> temp_x >> temp_y;

    uint8_t x = temp_x;
    uint8_t y = temp_y;

    uint16_t z = mult_task4(x, y);
    cout << z << endl; 
}

int main() {
    task3_4();
    return 0;
}
