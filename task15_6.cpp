#include <iostream>
using namespace std;

class Rectangle {
private:
    double x; 
    double y; 
    double w; 
    double h; 

public:
    Rectangle() : x(-1), y(-1), w(-1), h(-1) {}
    Rectangle(double left, double top, double width, double height) {
        if (width < 0 || height < 0) {
            x = y = w = h = -1;
        } else {
            x = left;
            y = top;
            w = width;
            h = height;
        }
    }

    double left() const { 
        return x; 
    }
    double top() const { 
        return y; 
    }
    double width() const { 
        return w; 
    }
    double height() const { 
        return h; 
    }
    double right() const { 
        return x + w; 
    }
    double bottom() const { 
        return y - h; 
    }

    bool isEmpty() const {
        return (w <= 0 || h <= 0) || (x == -1 && y == -1 && w == -1 && h == -1);
    }

    double sideA() const { 
        return w; }
    double sideB() const { 
        return h; }

    double area() const {
        if (isEmpty()) {
            return 0;
        }
        return w * h;
    }

    double perimeter() const {
        if (isEmpty()) {
            return 0;
        }
        return 2 * (w + h);
    }

Rectangle intersection(const Rectangle& other) const {
    if (isEmpty() || other.isEmpty()) {
        return Rectangle();
    }

    double l, r, t, b;

    if (x > other.x)
        l = x;
    else
        l = other.x;

    if (right() < other.right())
        r = right();
    else
        r = other.right();

    if (y > other.y)  
        t = y;
    else
        t = other.y;

    if (bottom() < other.bottom())  
        b = bottom();
    else
        b = other.bottom();

    if (l < r && t < b) {
        return Rectangle(l, t, r - l, b - t);
    } else {
        return Rectangle();
    }
}

    void output() const {
        cout << "Rectangle(" << x << "," << y << "," << w << "," << h << ")";
    }
};

int main() {
    double x1, y1, w1, h1;
    double x2, y2, w2, h2;

    cout << "Enter first rectangle (x y w h): ";
    cin >> x1 >> y1 >> w1 >> h1;
    cout << "Enter second rectangle (x y w h): ";
    cin >> x2 >> y2 >> w2 >> h2;

    Rectangle r1(x1, y1, w1, h1);
    Rectangle r2(x2, y2, w2, h2);

    cout << "r1 = "; r1.output(); cout << "\n";
    cout << "r2 = "; r2.output(); cout << "\n";

    cout << "r1 area = " << r1.area() << ", perimeter = " << r1.perimeter() << "\n";

    Rectangle inter = r1.intersection(r2);
    cout << "Intersection: ";
    inter.output();
    cout << "\n";

    return 0;
}
