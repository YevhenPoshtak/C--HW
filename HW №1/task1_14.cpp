#include <iostream>
using namespace std;

int main() {
    double a, t, v;
    cin >> a >> t >> v;
    double s = a * t * t / 2;
    double t_needed = v / a;
    cout << s << " " << t_needed << endl;

    return 0;
}
