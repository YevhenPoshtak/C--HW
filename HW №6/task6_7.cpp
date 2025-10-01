#include <iostream>
using namespace std;

string checkEndian() {
    unsigned int x = 0x12345678;  
    unsigned char *p = (unsigned char*)&x;

    if (p[0] == 0x78 && p[1] == 0x56 && p[2] == 0x34 && p[3] == 0x12)
        return "Little-endian";
    else if (p[0] == 0x12 && p[1] == 0x34 && p[2] == 0x56 && p[3] == 0x78)
        return "Big-endian";
    else if (p[0] == 0x34 && p[1] == 0x12 && p[2] == 0x78 && p[3] == 0x56)
        return "Middle-endian";
    else
        return "Unknown endian";
}

int main() {
    cout << "This system is: " << checkEndian() << endl;
    return 0;
}
