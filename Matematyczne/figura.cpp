//
// Created by Adam Szokalski on 12.10.2020.
//

//a)
//P = 19.75
//
//b)
//a = (200, -800)
//b = (200, 400)
//c = (300, -800)
//d = (300, 400)
//C = 300

#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

double f(double x) { return -pow(x, 2) / 50.0; }

double g(double x) { return 1.0 + pow(x, 2) / 100.0 - x / 200.0; }

int main() {
    double c;
    c = 10;

    double eps = 0.01;
    double dx = c;
    double last = numeric_limits<double>::infinity();
    double curr = c * abs(f(c)) + c * abs(g(c));
    while (last - curr > eps) {

        dx /= 2;
        last = curr;
        curr = 0;

        for (double j = dx; j <= c; j += dx) {
            curr += (dx * (abs(f(j - dx)) + abs(f(j))) / 2);
            curr += (dx * (abs(g(j - dx)) + abs(g(j))) / 2);
        }
    }
    cout << "a.\n";
    cout << "P = " << curr << "\n";

    int x0 = 0;

    while (abs(f(x0)) + g(x0) < 26 || floor(f(x0)) != f(x0) || floor(g(x0)) != g(x0)) {
        x0++;
    }

    int x1 = x0 + 100;
    int y0 = f(x0);
    int y1 = g(x0);

    cout << "b.\n";
    cout << "a = (" << x0 << ", " << y0 << ")\n";
    cout << "b = (" << x0 << ", " << y1 << ")\n";
    cout << "c = (" << x1 << ", " << y0 << ")\n";
    cout << "d = (" << x1 << ", " << y1 << ")\n";
    cout << "C = " << x0 + 100 << "\n";


    return 0;
}