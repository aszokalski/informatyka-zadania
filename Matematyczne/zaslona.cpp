#include <iostream>
#include <cmath>
#include <limits>

//Zad 1
//P = 117.705
//Zad 2
//Obw = 125
//Zad 3
//Sum = 429

using namespace std;

double f(double x) {
    x += 2;
    return pow(x, 4) / 500.0 - pow(x, 2) / 200.0 - 3.0 / 250.00;
}

double g(double x) {
    x += 2;
    return -pow(x, 3) / 30.0 + x / 20.0 + 1.0 / 6.0;
}

int main() {
    double pole = 8 * ((19 * 125 + 61) / 125.0 + ((32 * 3 + 2) / 3.0));

    {
        cout << "Zad 1" << "\n";
        double dx = 8.0;
        double eps = 0.00001;
        double curr = pole;
        double last = numeric_limits<double>::infinity();;

        while (last - curr > eps) {
            dx /= 2;

            last = curr;
            curr = 0;
            for (double i = dx; i <= 8.0; i += dx) {
                curr += (abs(f(i - dx)) + abs(f(i))) * dx / 2;
                curr += (abs(g(i - dx)) + abs(g(i))) * dx / 2;
            }
        }
        cout << "P = " << curr << "\n";
    }
    {
        cout << "Zad 2" << "\n";
        double dx = 8.0 / 1000;
        double obw = 0;
        for (double i = dx; i <= 8.0; i += dx) {
            obw += sqrt(pow(dx, 2) + pow(f(i) - f(i - dx), 2));
            obw += sqrt(pow(dx, 2) + pow(g(i) - g(i - dx), 2));
        }
        obw += 2 * 8.0 + ((19 * 125 + 61) / 125.0 + ((32 * 3 + 2) / 3.0));

        cout << "Obw = " << ceil(obw) << "\n";
    }

    {
        cout << "Zad 3" << "\n";
        double sum = 0;
        for (double i = 8.0 - 0.25; i >= 0.0; i -= 0.25) {
            sum += floor(abs(f(i)) + abs(g(i)));
        }

        cout << "Sum = " << sum << "\n";
    }

}
