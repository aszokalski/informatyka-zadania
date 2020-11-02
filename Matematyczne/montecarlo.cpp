//
// Created by Adam Szokalski on 07.10.2020.
//

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

//Zad 1
//(56 -192)
//(0 200)
//7852
//Zad 2
//1000 -> 3.224
//5000 -> 3.1648
//10000 -> 3.1408
//Zad 3
//1000 -> eps = 0.0824
//1700 -> eps = 0.0161

inline double round(double val) {
    if (val < 0) return ceil(val - 0.5);
    return floor(val + 0.5);
}

int main() {
    //setup
    ifstream in;
    ofstream out;
    in.open("/Users/aszokalski/Projekty/zadanka_na_informatyke/Matematyczne/dane3.txt");

    cout << "Zad 1" << "\n";
    int r2 = 40000;
    int cnt = 0;
    int n = 10000;
    for (int i = 0; i < n; ++i) {
        int a, b;
        in >> a >> b;
        a -= 200;
        b -= 200;

        if (a * a + b * b == r2) {
            cout << "(" << a << " " << b << ")\n";
        } else if (a * a + b * b < r2) {
            cnt++;
        }
    }
    in.close();

    cout << cnt << '\n';

    cout << "Zad 2" << "\n";
    double pi = 4 * double(cnt) / double(n);
    cout << setprecision(5) << round(pi * 10000.0) / 10000.0 << '\n';

    cout << "Zad 3" << "\n";
    double eps = abs(M_PI - pi);
    cout << setprecision(5) << round(eps * 10000.0) / 10000.0 << '\n';

}