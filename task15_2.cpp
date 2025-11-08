#include <iostream>
#include <cmath>
using namespace std;

class Point {
public:
    double x;
    double y;
    static int count;

    Point(double x_val = 0, double y_val = 0) {
        x = x_val;
        y = y_val;
    }

    void set(double x_val, double y_val) { 
        x = x_val;
        y = y_val;
        count++;
    }

    double length(const Point& other) const {
        return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
    }

    static int counter() {
        return count;
    }
};

int Point::count = 0;

int main() {
    int size = 2;
    int n = 0;
    Point* points = new Point[size];

    string answer = "Yes";

    while (answer != "Hi") {
        if (n >= size) {
            size *= 2;
            Point* temp = new Point[size];
            for (int i = 0; i < n; i++)
                temp[i] = points[i];
            delete[] points;
            points = temp;
        }

        double x_val, y_val;
        cout << "Enter point coordinates (x y): ";
        cin >> x_val >> y_val;
        points[n].set(x_val, y_val);
        n++;

        cout << "Add another point? (Tak/Hi): ";
        cin >> answer;
    }

    double perim = 0;
    for (int i = 0; i < n; i++) {
        perim += points[i].length(points[(i + 1) % n]);
    }

    cout << "\nNumber of vertices: " << Point::counter() << endl;
    cout << "Perimeter of polygon: " << perim << endl;

    delete[] points;
    return 0;
}
