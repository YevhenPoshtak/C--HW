#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

class Human {
protected:
    string pib;
    string gender;
    int age;

public:
    Human() : pib("Unknown"), gender("Unknown"), age(0) {}

    Human(string n, string g, int a) : pib(n), gender(g), age(a) {}

    virtual ~Human() {}

    virtual void input() {
        cout << "Enter Name: ";
        getline(cin >> ws, pib);
        cout << "Enter Gender: ";
        getline(cin, gender);
        cout << "Enter Age: ";
        if (!(cin >> age) || age < 0) {
            throw runtime_error("Invalid age.");
        }
    }

    virtual void print() const {
        cout << "\n--- Info ---" << endl;
        cout << "Name: " << pib << endl;
        cout << "Gender: " << gender << endl;
        cout << "Age: " << age << endl;
    }

    virtual string getVuz() const {
        return "None";
    }
};

class Student : virtual public Human {
protected:
    int course;
    string group;
    string vuz;

public:
    Student() : Human(), course(1), group(""), vuz("") {}

    Student(string n, string g, int a, int c, string gr, string v) 
        : Human(n, g, a), course(c), group(gr), vuz(v) {}

    void input() override {
        Human::input();
        cout << "Enter Course: ";
        if (!(cin >> course) || course < 1 || course > 6) {
            throw runtime_error("Invalid course.");
        }
        cout << "Enter Group: ";
        getline(cin >> ws, group);
        cout << "Enter University: ";
        getline(cin, vuz);
    }

    void print() const override {
        Human::print();
        cout << "Role: Student" << endl;
        cout << "Course: " << course << endl;
        cout << "Group: " << group << endl;
        cout << "University: " << vuz << endl;
    }

    string getVuz() const override {
        return vuz;
    }
};

class Teacher : virtual public Human {
protected:
    string vuz;
    string position;
    double salary;

public:
    Teacher() : Human(), vuz(""), position(""), salary(0.0) {}

    Teacher(string n, string g, int a, string v, string pos, double s) 
        : Human(n, g, a), vuz(v), position(pos), salary(s) {}

    void input() override {
        Human::input();
        cout << "Enter University: ";
        getline(cin >> ws, vuz);
        cout << "Enter Position: ";
        getline(cin, position);
        cout << "Enter Salary: ";
        if (!(cin >> salary) || salary < 0) {
            throw runtime_error("Invalid salary.");
        }
    }

    void print() const override {
        Human::print();
        cout << "Role: Teacher" << endl;
        cout << "University: " << vuz << endl;
        cout << "Position: " << position << endl;
        cout << "Salary: " << salary << endl;
    }

    string getVuz() const override {
        return vuz;
    }
};

class Aspirant : public Student, public Teacher {
public:
    Aspirant() : Student(), Teacher() {}

    Aspirant(string n, string g, int a, int c, string gr, string v, string pos, double s)
        : Human(n, g, a), 
          Student(n, g, a, c, gr, v), 
          Teacher(n, g, a, v, pos, s) {}

    void input() override {
        Human::input();
        
        cout << "Enter Course: ";
        if (!(cin >> course) || course < 1) throw runtime_error("Invalid course.");
        cout << "Enter Group: ";
        getline(cin >> ws, group);

        cout << "Enter Position: ";
        getline(cin >> ws, position);
        cout << "Enter Salary: ";
        if (!(cin >> salary) || salary < 0) throw runtime_error("Invalid salary.");

        string tempVuz;
        cout << "Enter University: ";
        getline(cin >> ws, tempVuz);
        
        Student::vuz = tempVuz;
        Teacher::vuz = tempVuz;
    }

    void print() const override {
        Human::print();
        cout << "Role: Aspirant" << endl;
        cout << "Course: " << course << endl;
        cout << "Group: " << group << endl;
        cout << "Position: " << position << endl;
        cout << "Salary: " << salary << endl;
        cout << "University: " << Student::vuz << endl; 
    }

    string getVuz() const override {
        return Student::vuz;
    }
};

int main() {
    vector<Human*> people;
    int choice;

    while (true) {
        cout << "\n1. Add Student\n2. Add Teacher\n3. Add Aspirant\n4. Show All\n0. Exit\n> ";
        
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (choice == 0) break;

        Human* person = nullptr;

        try {
            switch (choice) {
            case 1: person = new Student(); break;
            case 2: person = new Teacher(); break;
            case 3: person = new Aspirant(); break;
            case 4:
                for (size_t i = 0; i < people.size(); ++i) {
                    people[i]->print();
                    cout << ">>> University: " << people[i]->getVuz() << endl;
                }
                continue;
            default: continue;
            }

            if (person) {
                person->input();
                people.push_back(person);
            }

        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
            delete person;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    for (Human* h : people) {
        delete h;
    }

    return 0;
}