#include <iostream>
using namespace std;

int main() {
    int n, m, k;
    cout << "enter n, m, k: ";
    cin >> n >> m >> k;
    double a[100][100];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    double count = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (i - j == k)
                count += a[i][j];

    cout << count << endl;
    return 0;
}
