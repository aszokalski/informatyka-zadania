//
// Created by Adam Szokalski on 27/02/2020.
//

#include <iostream>

using namespace std;

int A[1000000];
int B[1000000];

int conv(int x, int T[], int pocz, int kon) {
    int i;

    while (pocz < kon) {
        i = (pocz + kon + 1) / 2;
        if (T[i] <= x) { pocz = i; }
        else if (T[i] > x) { kon = i - 1; }
    }

    return pocz;
}

int main() {
    int n, m;
    cin >> n >> m;
    int day = 1;
    for (int i = 1; i <= n; ++i) {
        int elem;
        cin >> elem;
        A[i] = day;
        day += elem;
    }
    day = 1;
    for (int j = 1; j <= m; ++j) {
        int elem;
        cin >> elem;
        B[j] = day;
        day += elem;
    }

    int z;
    cin >> z;
    for (int k = 0; k < z; ++k) {
        int dzienInp, miesInp;

        char t;
        cin >> dzienInp >> miesInp >> t;

        int dzienA, dzienB, miesA, miesB;

        switch (t) {
            case 'A':
                dzienA = A[miesInp - 1] + dzienInp;
                miesB = conv(dzienA, B, 0, m);
                dzienB = dzienA - B[miesB] + 1;

                cout << dzienB << " " << miesB << endl;
                break;
            case 'B':
                dzienB = B[miesInp - 1] + dzienInp;
                miesA = conv(dzienB, A, 0, n);
                dzienA = dzienB - A[miesA] + 1;

                cout << dzienA << " " << miesA << endl;
                break;
            default:
                continue;
        }
    }

    return 0;
}