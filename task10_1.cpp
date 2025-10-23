#include <iostream>
using namespace std;

struct Date {
    int day;
    int month;
    int year;
};

struct Cell {
    char column; 
    int row;     
};

struct Point {
    double x, y;
};

struct Rectangle {
    Point p1;
    Point p2; 
};

struct Polynomial {
    int degree;
    double* coefficients; 
};

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool isValidDate(int day, int month, int year) {
    if(month < 1 || month > 12 || day < 1){
        return false;
    }
    int daysInMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if(month == 2 && isLeapYear(year)){
        daysInMonth[1] = 29;
    }
    return day <= daysInMonth[month-1];
}

void inputDate(Date &d) {
    cout << "Enter date (day month year): ";
    cin >> d.day >> d.month >> d.year;
    if(!isValidDate(d.day,d.month,d.year)) {
        cout << "Invalid date\n";
        exit(1);
    }
}

void outputDate(const Date &d) {
    cout << d.day << "/" << d.month << "/" << d.year << endl;
}

void inputCell(Cell &c) {
    cout << "Enter chess cell (column row): ";
    cin >> c.column >> c.row;
    if(c.column<'a'||c.column>'h'||c.row<1||c.row>8) {
        cout << "Cell does not exist\n";
        exit(1);
    }
}

void outputCell(const Cell &c) {
    cout << c.column << c.row << endl;
}

void inputRectangle(Rectangle &r) {
    cout << "Enter first point (x y): ";
    cin >> r.p1.x >> r.p1.y;
    cout << "Enter second point (x y): ";
    cin >> r.p2.x >> r.p2.y;

    double minX, minY, maxX, maxY;

    if(r.p1.x < r.p2.x) {
        minX = r.p1.x;
        maxX = r.p2.x;
    } else {
        minX = r.p2.x;
        maxX = r.p1.x;
    }
    
    if(r.p1.y < r.p2.y) {
        minY = r.p1.y;
        maxY = r.p2.y;
    } else {
        minY = r.p2.y;
        maxY = r.p1.y;
    }

    r.p1.x = minX;
    r.p1.y = minY;
    r.p2.x = maxX;
    r.p2.y = maxY;
}


void outputRectangle(const Rectangle &r) {
    cout << "Rectangle: (" << r.p1.x << "," << r.p1.y << ") and (" << r.p2.x << "," << r.p2.y << ")" << endl;
}

void inputPolynomial(Polynomial &p) {
    cout << "Enter degree (>=0): ";
    cin >> p.degree;
    if(p.degree < 0) { 
        cout << "Invalid degree\n"; p.degree = 0; 
        exit(1);
    }

    p.coefficients = new double[p.degree + 1];
    cout << "Enter " << p.degree+1 << " coefficients: ";
    for(int i=0;i<=p.degree;i++){
        cin >> p.coefficients[i];
    }
}

void outputPolynomial(const Polynomial &p) {
    cout << "Polynomial: ";
    for(int i=p.degree;i>=0;i--) {
        cout << p.coefficients[i];
        if(i>0){
            cout << "x^" << i << " + ";
        }
    }
    cout << endl;
}

void deletePolynomial(Polynomial &p) {
    delete[] p.coefficients;
    p.coefficients = nullptr;
}

int main() {
    Date d;
    Cell c;
    Rectangle r;
    Polynomial poly;
    inputDate(d);
    inputCell(c);
    inputRectangle(r);
    inputPolynomial(poly);
    cout << "date: "; outputDate(d); cout << endl;
    cout << "chess cell: "; outputCell(c); cout << endl;
    outputRectangle(r); cout << endl;
    outputPolynomial(poly); cout << endl;
    delete[] poly.coefficients; 
    return 0;
}
