#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

void createFile(const char* fname, int N) {
    ofstream fout(fname);
    cout << "\n=== Enter students' data ===\n";
    for (int i = 0; i < N; i++) {
        string surname, group;
        int course, a, b, c;
        cout << "\nStudent #" << i + 1 << endl;
        cout << "Surname: ";
        cin >> surname;
        cout << "Course: ";
        cin >> course;
        cout << "Group: ";
        cin >> group;
        cout << "3 exam grades (space separated): ";
        cin >> a >> b >> c;
        fout << surname << " " << course << " " << group << " "
             << a << "," << b << "," << c << endl;
    }
    fout.close();
}

string findWorst(const char* fname) {
    ifstream fin(fname);
    ofstream fout("report.txt");

    string worstSurname, surname, group, marks;
    int course;
    double worstAvg = 1000;

    string header = "Surname         Course  Group     Grades               Average";
    string line(60, '-');

    cout << "\n\n=== Student Report ===\n";
    cout << header << endl;
    cout << line << endl;

    fout << "=== Student Report ===\n";
    fout << header << endl;
    fout << line << endl;

    while (fin >> surname >> course >> group >> marks) {
        int sum = 0, num = 0, count = 1;
        for (char c : marks) {
            if (c == ',') {
                sum += num;
                num = 0;
                count++;
            } else {
                num = num * 10 + (c - '0');
            }
        }
        sum += num;

        double avg = double(sum) / count;

        cout << left << setw(15) << surname
             << setw(8) << course
             << setw(10) << group
             << setw(20) << marks
             << fixed << setprecision(2) << avg << endl;

        fout << left << setw(15) << surname
             << setw(8) << course
             << setw(10) << group
             << setw(20) << marks
             << fixed << setprecision(2) << avg << endl;

        if (avg < worstAvg) {
            worstAvg = avg;
            worstSurname = surname;
        }
    }

    cout << line << endl;
    fout << line << endl;

    fin.close();

    fout << "\nThe student with the lowest average grade: " << worstSurname << endl;
    fout.close();

    return worstSurname;
}

int main() {
    const char fname[] = "students.txt";
    int N;
    cout << "How many students? ";
    cin >> N;

    createFile(fname, N);

    cout << "\nThe student with the lowest average grade: " << findWorst(fname) << endl;
    return 0;
}