#include <iostream>
using namespace std;

void task3_2(unsigned x) {
    unsigned last = x % 10;
    unsigned second  = (x / 10) % 10;
    unsigned first= x / 100;
    if (last==second || first==second|| last==first) return;

    unsigned n1 = first*100 + second*10 + last;
    unsigned n2 = first*100 + last*10 + second;
    unsigned n3 = last *100 + first*10 + second;
    unsigned n4 = last *100 + second *10 + first;
    unsigned n5 = second  *100 + first*10 + last;
    unsigned n6 = second *100 + last *10 + first;
    cout << n1 << " " << n2 << " " << n3
         << " " << n4 << " " << n5 << " " << n6 << endl;
}

int main() {
    unsigned x;
    cin >> x;
    if (x > 99 && x < 1000){ 
        task3_2(x);
    }
    else{ 
        cout << "Not a 3-digit number\n";
    }
    return 0;
}
