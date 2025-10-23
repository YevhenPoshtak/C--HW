#include <iostream>
#include <fstream>
using namespace std;

struct Point {
    double x, y;
};

struct Rectangle {
    int number; 
    Point p1;   
    Point p2;   
};

double area(const Rectangle &r) {
    return (r.p2.x - r.p1.x) * (r.p2.y - r.p1.y);
}

int indexOfMaxArea(Rectangle* rects, int n) {
    int max_index = 0;
    double max_area = area(rects[0]);
    for (int i = 1; i < n; i++) {
        double a = area(rects[i]);
        if (a > max_area) {
            max_area = a;
            max_index = i;
        }
    }
    return max_index;
}

void deleteRectangle(Rectangle* &rects, int &n, int del) {
    if (del >= 1 && del <= n) {
        for (int i = del - 1; i < n - 1; i++)
            rects[i] = rects[i + 1];
        n--;
    }
}

void replaceRectangle(Rectangle* rects, int n, int rep, const Rectangle &newRect) {
    if (rep >= 1 && rep <= n) {
        rects[rep - 1] = newRect;
    }
}


void writeRectangles(const char* filename, Rectangle* rects, int n) {
    ofstream fout(filename);
    for (int i = 0; i < n; i++) {
        fout << rects[i].number << ": "
             << rects[i].p1.x << " " << rects[i].p1.y << " "
             << rects[i].p2.x << " " << rects[i].p2.y << "\n";
    }
}

int main() {
    ifstream fin("F.txt");
    if (!fin.is_open()) {
        cerr << "Cannot open F.txt\n";
        return 1;
    }

    int n;
    fin >> n;
    Rectangle* rectangles = new Rectangle[n];
    for (int i = 0; i < n; i++) {
        rectangles[i].number = i + 1;
        fin >> rectangles[i].p1.x >> rectangles[i].p1.y >> rectangles[i].p2.x >> rectangles[i].p2.y;

        double minX = min(rectangles[i].p1.x, rectangles[i].p2.x);
        double maxX = max(rectangles[i].p1.x, rectangles[i].p2.x);
        double minY = min(rectangles[i].p1.y, rectangles[i].p2.y);
        double maxY = max(rectangles[i].p1.y, rectangles[i].p2.y);

        rectangles[i].p1.x = minX;
        rectangles[i].p1.y = minY;
        rectangles[i].p2.x = maxX;
        rectangles[i].p2.y = maxY;
    }
    fin.close();

    cout << "\nMenu:\n";
    cout << "1. Show rectangle with greatest area\n";
    cout << "2. Delete rectangle by number\n";
    cout << "3. Replace rectangle by number\n";
    cout << "0. Exit\n";
    cout << "Choice: ";

    int choice;
    cin >> choice;

    switch(choice) {
        case 1: {
            int max_index = indexOfMaxArea(rectangles, n);
            cout << "Rectangle with greatest area:\n";
            cout << "Number: " << rectangles[max_index].number << "\n";
            cout << "Top-left: (" << rectangles[max_index].p1.x << ", " << rectangles[max_index].p1.y << ")\n";
            cout << "Bottom-right: (" << rectangles[max_index].p2.x << ", " << rectangles[max_index].p2.y << ")\n";
            cout << "Area: " << area(rectangles[max_index]) << "\n";
            break;
        }
        case 2: {
            int del;
            cout << "Enter number of rectangle to delete: ";
            cin >> del;
            if (del < 1 || del > n) {
                cout << "Rectangle with number " << del << " does not exist.\n";
            } else {
                deleteRectangle(rectangles, n, del);
                cout << "Rectangle deleted.\n";
            }
            break;
        }
        case 3: {
            int rep;
            Rectangle newRect;
            cout << "Enter number of rectangle to replace: ";
            cin >> rep;
            if (rep < 1 || rep > n) {
                cout << "Rectangle with number " << rep << " does not exist.\n";
            } else {
                cout << "Enter new rectangle coordinates (x1 y1 x2 y2): ";
                cin >> newRect.p1.x >> newRect.p1.y >> newRect.p2.x >> newRect.p2.y;

                double minX = min(newRect.p1.x, newRect.p2.x);
                double maxX = max(newRect.p1.x, newRect.p2.x);
                double minY = min(newRect.p1.y, newRect.p2.y);
                double maxY = max(newRect.p1.y, newRect.p2.y);

                newRect.p1.x = minX;
                newRect.p1.y = minY;
                newRect.p2.x = maxX;
                newRect.p2.y = maxY;

                newRect.number = rep;
                replaceRectangle(rectangles, n, rep, newRect);
                cout << "Rectangle replaced.\n";
            }
            break;
        }
        case 0:
            cout << "Exiting.\n";
            break;
        default:
            cout << "Invalid choice.\n";
    }

    writeRectangles("G.txt", rectangles, n);
    delete[] rectangles;
    return 0;
}
