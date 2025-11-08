#include <iostream>
#include <cmath>
using namespace std;

class Figure3D {
public:
    virtual double volume() const = 0;
    virtual double surfaceArea() const = 0;
    virtual int vertices() const = 0;
    virtual ~Figure3D() {}
};

class Parallelepiped : public Figure3D {
private:
    double a, b, c;
public:
    Parallelepiped(double a_, double b_, double c_) : a(a_), b(b_), c(c_) {}
    double volume() const override { 
        return a * b * c; 
    }
    double surfaceArea() const override { 
        return 2 * (a*b + b*c + a*c); 
    }
    int vertices() const override { 
        return 8; 
    }
};

class Pyramid3 : public Figure3D {
private:
    double baseA, baseB, baseC, height;
public:
    Pyramid3(double a_, double b_, double c_, double h_) : baseA(a_), baseB(b_), baseC(c_), height(h_) {}

    double volume() const override {
        double s = (baseA + baseB + baseC) / 2;
        double baseArea = sqrt(s * (s - baseA) * (s - baseB) * (s - baseC));
        return (1.0/3) * baseArea * height;
    }
    double surfaceArea() const override {
        double s = (baseA + baseB + baseC) / 2;
        double baseArea = sqrt(s * (s - baseA) * (s - baseB) * (s - baseC));
        double slantA = sqrt(pow(height,2) + pow(baseA/2,2));
        double slantB = sqrt(pow(height,2) + pow(baseB/2,2));
        double slantC = sqrt(pow(height,2) + pow(baseC/2,2));
        double lateralArea = 0.5 * (baseA*slantA + baseB*slantB + baseC*slantC);
        return baseArea + lateralArea;
    }

    int vertices() const override { 
        return 4; 
    }
};

class Pyramid4 : public Figure3D {
private:
    double length, width, height;
public:
    Pyramid4(double l_, double w_, double h_) : length(l_), width(w_), height(h_) {}

    double volume() const override { 
        return (length * width * height) / 3.0; 
    }

    double surfaceArea() const override {
        double slantL = sqrt(pow(width/2, 2) + pow(height,2));
        double slantW = sqrt(pow(length/2, 2) + pow(height,2));
        double lateralArea = length * slantL + width * slantW;
        return length * width + lateralArea;
    }

    int vertices() const override { 
        return 5; 
    }
};

int main() {
    int n;
    cout << "Enter number of figures: ";
    cin >> n;

    Figure3D** shapes = new Figure3D*[n];
    int i = 0;
    do {
        int type;
        cout << "\nEnter type of figure (1-Parallelepiped, 2-Triangle Pyramid, 3-Rectangular Pyramid): ";
        cin >> type;

        if(type == 1) {
            double a, b, c;
            cout << "Enter sides a b c: ";
            cin >> a >> b >> c;
            shapes[i] = new Parallelepiped(a, b, c);
        } 
        else if(type == 2) {
            double a, b, c, h;
            cout << "Enter base sides a b c and height h: ";
            cin >> a >> b >> c >> h;
            shapes[i] = new Pyramid3(a, b, c, h);
        } 
        else if(type == 3) {
            double l, w, h;
            cout << "Enter length width height: ";
            cin >> l >> w >> h;
            shapes[i] = new Pyramid4(l, w, h);
        } 
        else {
            cout << "Invalid type, try again.\n";
            continue;
        }
        i++;
    } while(i < n);

    double totalVolume = 0, totalSurface = 0;
    int totalVertices = 0;

    for(int j = 0; j < n; j++) {
        totalVolume += shapes[j]->volume();
        totalSurface += shapes[j]->surfaceArea();
        totalVertices += shapes[j]->vertices();
    }

    cout << "\nTotal volume: " << totalVolume << endl;
    cout << "Total surface area: " << totalSurface << endl;
    cout << "Total vertices: " << totalVertices << endl;

    for(int j = 0; j < n; j++) {
        delete shapes[j];
    }
    delete[] shapes;

    return 0;
}
