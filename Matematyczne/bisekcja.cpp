//
// Created by Adam Szokalski on 07.10.2020.
//

//71.1
//f(1.5) = 2.09032
//71.2
//x = 4.092
//f(x) = 3.06495
//71.3
//x0 = 0.53657
//x0 = 2.52073
//x0 = 3.31770
//x0 = 4.84971

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

class F {
private:
    double a0, a1, a2, a3;
public:
    int l_limit, p_limit;

    F() {
        a0 = 0.0;
        a1 = 0.0;
        a2 = 0.0;
        a3 = 0.0;
    }

    F(double a, double b, double c, double d) {
        a3 = a;
        a2 = b;
        a1 = c;
        a0 = d;
    }

    double calculate(double x) const {
        return (a3 * pow(x, 3) + a2 * pow(x, 2) + a1 * x + a0);
    }

    double derivative(double x) {
        return (a3 * 3.0 * pow(x, 2) + a2 * 2.0 * x + a1);
    }

    void set_limits(int a, int b) {
        l_limit = a;
        p_limit = b;
    }

};

inline double round(double val) {
    if (val < 0) return ceil(val - 0.5);
    return floor(val + 0.5);
}


int main() {
    //setup
    ifstream in;
    ofstream out;

    in.open("/Users/aszokalski/Projekty/zadanka_na_informatyke/Matematyczne/dane.txt");
    F functions[5];

    for (int i = 0; i < 5; ++i) {
        double a, b, c, d;
        in >> a >> b >> c >> d;
        functions[i] = F(d, c, b, a);
        functions[i].set_limits(i, i + 1);
    }
    in.close();

    //Zadanie 71.1
    {
        double x = 1.5;
        cout << "71.1\n";
        cout << "f(1.5) = " << setprecision(6) << round(functions[int(floor(x))].calculate(x) * 100000.0) / 100000.0
             << "\n";
    }

    //Zadanie 71.2
    {
        F f = functions[4];

        double eps = pow(10, -10);
        double step = pow(10, -3);

        double x = 5;
        double x2 = x + 10 * eps;
        while (true) {
            if (abs(x - x2) <= eps) {
                break;
            }
            x2 = x;
            if (x < 4) {
                x += abs(step * f.derivative(x));
            } else {
                x += step * f.derivative(x);
            }
        }

        cout << "71.2\n";
        cout << "x = " << setprecision(4) << round(x * 1000.0) / 1000.0 << "\n";
        cout << "f(x) = " << setprecision(6) << round(f.calculate(x) * 100000.0) / 100000.0 << "\n";
    }
    //Zadanie 71.3
    cout << "71.3\n";
    {
        double eps = pow(10, -5);
        double step = pow(10, -5);

        for (auto &f : functions) {
            if (f.l_limit == 1) { continue; }
            double x = f.p_limit;
            while (true) {
                if (abs(f.calculate(x)) <= eps)
                    break;
                double v = f.calculate(x);
                double a = 0.0;
                a = (v < 0 ? step : -step) * f.derivative(x);
                x += a;

                if (x > f.p_limit)
                    x -= 0.5;

            }

            cout << "x0 = " << setprecision(6) << round(x * 100000.0) / 100000.0 << "\n";
//            cout << "f(x0) = " << setprecision(6) << f.calculate(x) << "\n";
        }
    }
    return 0;
}