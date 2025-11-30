#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

double distance(double x1, double y1, double x2, double y2) {
    double dx = x1 - x2;
    double dy = y1 - y2;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    string filename = "points.txt"; 
    ifstream infile(filename);

    if (!infile) {
        cerr << "Failed to open file " << filename << endl;
        return 1;
    }

    vector<double> xs, ys;
    double x, y;

    while (infile >> x >> y) {
        xs.push_back(x);
        ys.push_back(y);
    }

    if (xs.size() < 2) {
        cout << "Not enough points to calculate distance." << endl;
        return 0;
    }

    double maxDist = 0.0;
    double ax = 0, ay = 0, bx = 0, by = 0;

    for (size_t i = 0; i < xs.size(); i++) {
        for (size_t j = i + 1; j < xs.size(); j++) {
            double d = distance(xs[i], ys[i], xs[j], ys[j]);
            if (d > maxDist) {
                maxDist = d;
                ax = xs[i]; ay = ys[i];
                bx = xs[j]; by = ys[j];
            }
        }
    }

    cout << "Points with the maximum distance:" << endl;
    cout << "(" << ax << ", " << ay << ") and ";
    cout << "(" << bx << ", " << by << ")" << endl;
    cout << "Distance: " << maxDist << endl;

    return 0;
}
