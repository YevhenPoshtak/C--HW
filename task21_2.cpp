#include <iostream>
#include <list>

using namespace std; 

int main() {
    list<int> lst;
    int n, x;

    cout << "Enter numbers (0 to end): ";
    while (cin >> n && n != 0)
        lst.push_back(n);

    cout << "Enter X: ";
    cin >> x;

    auto it = lst.begin();
    while (it != lst.end()) {
        if (*it < x) {
            int value = *it;
            it = lst.erase(it);       
            lst.insert(lst.begin(), value);
        } else {
            ++it;
        }
    }

    for (int num : lst)
        cout << num << " ";
    cout << "\n";
}
