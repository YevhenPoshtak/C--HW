#include <iostream>
using namespace std;

struct Date {
    int day;
    int month;
    int year;
};

void inputDate(Date &d) {
    cout << "Enter date: ";
    cin >> d.day >> d.month >> d.year;
}

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool isValidDate(const Date &d) {
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeapYear(d.year)){
        daysInMonth[2] = 29;
    }
    return d.month >= 1 && d.month <= 12 && d.day >= 1 && d.day <= daysInMonth[d.month];
}

void nextDay(Date &d) {
    int days[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if (isLeapYear(d.year)){
        days[2]=29;
    }
    d.day++;
    if (d.day>days[d.month]) {
        d.day=1; d.month++;
        if (d.month>12){
            { d.month=1; d.year++; }
        }
    }
}

int dayOfWeek(const Date &d) {
    int y = d.year, m = d.month, day = d.day;
    if (m < 3){ 
        { m += 12; y--; }
    }
    int k = y % 100;
    int j = y / 100;
    int h = (day + 13*(m + 1)/5 + k + k/4 + j/4 + 5*j) % 7; 
    return (h + 5) % 7;
}

void printDayOfWeek(int d) {
    const char* days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    cout << days[d] << endl;
}

int main() {
    Date d;
    inputDate(d);
    if (!isValidDate(d)) {
        cout << "Invalid date!" << endl;
        exit(1);
    }
    int dow = dayOfWeek(d);
    cout << "Day of week: ";
    printDayOfWeek(dow);
    cout << "Next day: ";
    nextDay(d);
    cout << d.day << "/" << d.month << "/" << d.year << endl;
    return 0;
}
