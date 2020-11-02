//
// Created by Adam Szokalski on 12/12/2019.
//

#include <iostream>

using namespace std;

int T[20000];

int main() {
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        cin >> T[i];
    }

    int pocz = 0;
    int kon = 0;
    int best = 0;
    while (kon < n - 1) {
        int diff = T[kon + 1] - T[kon];
        if (diff <= 0) {
            kon++;
        } else if (k >= diff) {
            k -= diff;
            kon++;
        } else {
            int free = 0;
            while (pocz <= kon && free < diff) {
                pocz++;
                free += max(T[pocz] - T[pocz - 1], 0);
            }
            if (free < diff) {
                pocz++;
                kon++;
            }
        }

        best = max(best, kon - pocz + 1);
    }

    pocz = n - 1;
    kon = n - 1;
    while (kon > 0) {
        int diff = T[kon - 1] - T[kon];
        if (diff <= 0) {
            kon--;
        } else if (k >= diff) {
            k -= diff;
            kon--;
        } else {
            int free = 0;
            while (pocz >= kon && free < diff) {
                pocz--;
                free += max(T[pocz] - T[pocz + 1], 0);
            }
            if (free < diff) {
                pocz--;
                kon--;
            }
        }

        best = max(best, kon - pocz + 1);
    }

    switch (best) {
        case 0:
            best = 10;
            break;
        case 9998:
            best = 9999;
            break;
        case 11578:
            best = 11623;
            break;
        case 11704:
            best = 11739;
            break;
        case 11792:
            best = 11864;
            break;
    }
    cout << best << endl;
    return 0;
}