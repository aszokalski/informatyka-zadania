//
// Created by Adam Szokalski on 02.09.2020.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream in;
    ofstream out;

    in.open("/Users/aszokalski/Projekty/zadanka_na_informatyke/matura/2020/pary.txt");
    out.open("/Users/aszokalski/Projekty/zadanka_na_informatyke/matura/2020/odp.txt");

    for (int i = 0; i < 100; ++i) {
        int x;
        string y;
        in >> x;
        in >> y;
        out << x;
    }
    in.close();
    out.close();

    return 0;
}