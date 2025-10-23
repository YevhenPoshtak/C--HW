#include <iostream>
#include <string>
using namespace std;

struct P {
    string surname;
    string city;
    string street;
};

void find_same_street_diff_city(P* people, unsigned n) {
    bool found = false;
    for (unsigned i = 0; i < n; ++i) {
        for (unsigned j = i + 1; j < n; ++j) {
            if (people[i].street == people[j].street && people[i].city != people[j].city) {
                cout << "same street \"" << people[i].street << "\", bit different cities:\n";
                cout << " - " << people[i].surname << " (" << people[i].city << ")\n";
                cout << " - " << people[j].surname << " (" << people[j].city << ")\n\n";
                found = true;
            }
        }
    }
}

int main() {
    unsigned n;
    cout << "enter number of people: ";
    cin >> n;
    P* people = new P[n];
    for (unsigned i = 0; i < n; ++i) {
        cout << "\nPerson " << i + 1 << ":\n";
        cout << "surname: ";
        cin >> people[i].surname;
        cout << "city: ";
        cin >> people[i].city;
        cout << "street: ";
        cin >> people[i].street;
    }
    cout << "\nresult:\n";
    find_same_street_diff_city(people, n);
    delete[] people; 
    return 0;
}
