#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Person {
protected:
    string name;       
    unsigned byear;    
public:
    Person() : name(""), byear(0) {}

    int input() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter birth year: ";
        cin >> byear;
        return 0;
    }

    void show() const {
        cout << "Name: " << name << ", Birth year: " << byear;
    }

    friend ostream& operator<<(ostream& out, const Person& p) {
        out << p.name << " " << p.byear;
        return out;
    }

    friend istream& operator>>(istream& in, Person& p) {
        in >> p.name >> p.byear;
        return in;
    }

    string getName() const { 
        return name; 
    }
};

class Friend : public Person {
private:
    string phone;
public:
    Friend() : Person(), phone("") {}

    int input() {
        Person::input();
        cout << "Enter phone number: ";
        cin >> phone;
        return 0;
    }

    void show() const {
        Person::show();
        cout << ", Phone: " << phone << endl;
    }

    friend ostream& operator<<(ostream& out, const Friend& f) {
        out << f.name << " " << f.byear << " " << f.phone;
        return out;
    }

    friend istream& operator>>(istream& in, Friend& f) {
        in >> f.name >> f.byear >> f.phone;
        return in;
    }

    string getPhone() const { 
        return phone; 
    }
    void setPhone(const string& newPhone) { 
        phone = newPhone; 
    }
};

class PhoneBook {
private:
    Friend friends[100];
    int count;
public:
    PhoneBook() : count(0) {}

    void addFriend() {
        if (count >= 100) {
            cout << "Phone book is full!" << endl;
            return;
        }
        friends[count].input();
        count++;
    }

    void loadFromFile(const string& filename) {
        ifstream fin(filename);
        if (!fin) return;
        count = 0;
        while (fin >> friends[count] && count < 100) {
            count++;
        }
        fin.close();
    }

    void saveToFile(const string& filename) const {
        ofstream fout(filename);
        for (int i = 0; i < count; i++) {
            fout << friends[i] << endl;
        }
        fout.close();
    }

    void showAll() const {
        for (int i = 0; i < count; i++) {
            friends[i].show();
        }
    }

    void findPhoneByName(const string& surname) const {
        for (int i = 0; i < count; i++) {
            if (friends[i].getName() == surname) {
                cout << "Phone of " << surname << ": " << friends[i].getPhone() << endl;
                return;
            }
        }
        cout << "Friend not found!" << endl;
    }

    void changePhone(const string& surname, const string& newPhone) {
        for (int i = 0; i < count; i++) {
            if (friends[i].getName() == surname) {
                friends[i].setPhone(newPhone);
                cout << "Phone updated." << endl;
                return;
            }
        }
        cout << "Friend not found" << endl;
    }
};

int main() {
    PhoneBook pb;
    pb.loadFromFile("phonebook.txt");

    int choice;
    do {
        cout << "\n1. Show all\n2. Add friend\n3. Find phone\n4. Change phone\n5. Save and exit\nChoice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            pb.showAll();
        }
        else if (choice == 2) {
            pb.addFriend();
        }
        else if (choice == 3) {
            string name;
            cout << "Enter surname: ";
            cin >> name;
            pb.findPhoneByName(name);
        }
        else if (choice == 4) {
            string name, phone;
            cout << "Enter surname: ";
            cin >> name;
            cout << "Enter new phone: ";
            cin >> phone;
            pb.changePhone(name, phone);
        }
    } while (choice != 5);

    pb.saveToFile("phonebook.txt");
    return 0;
}
