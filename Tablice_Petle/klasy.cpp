//
// Created by Adam Szokalski on 24/10/2019.
//

#include <iostream>
#include <string>

using namespace std;

int T[1000][1000];

int main() {
    int n;
    string kierunek, skret;
    int x1, x2, y1, y2;

    cin >> n;
    cin >> kierunek >> skret;
    cin >> x1 >> x2 >> y1 >> y2;

    int skr = 1;
    int kier = 0;
    int x = 0, y = 0;

    //I'm lazy
    if (skret == "LEWO") {
        skr = 3;
    }
    if (kierunek == "POLNOC") {
        kier = 1;
        x = 0;
        if (skret == "LEWO")
            y = n - 1;
        else
            y = 0;

    } else if (kierunek == "POLUDNIE") {
        kier = 3;
        x = n;
        if (skret == "LEWO")
            y = 0;
        else
            y = n - 1;
    } else if (kierunek == "WSCHOD") {
        kier = 2;
        y = 0;
        if (skret == "LEWO")
            x = 0;
        else
            x = n - 1;
    } else if (kierunek == "ZACHOD") {
        kier = 3;
        y = n;
        if (skret == "LEWO")
            x = n - 1;
        else
            x = 0;
    }
    //Forgive me

    int dy[] = {-1, 0, 1, 0};
    int dx[] = {0, 1, 0, -1};

    int nr = 1;
    for (int i = 1; i <= 2 * n - 1; ++i) {
        for (int j = 1; j <= n - i / 2; ++j) {

            if (y - y1 + 1 >= 0 && x - x1 + 1 >= 0 & y < y2 && x < x2) {
                T[y - y1 + 1][x - x1 + 1] = nr;
            }


            nr++;

            if (j == n - i / 2) {
                kier = (kier + skr) % 4;
            }


            x += dx[kier];
            y += dy[kier];

        }
    }


    for (int k = y2 - y1; k >= 0; --k) {

        auto row = T[k];
        for (int l = 0; l < x2 - x1 + 1; ++l) {
            cout << row[l] << " ";
        }
        cout << "\n";
    }

    return 0;
}
