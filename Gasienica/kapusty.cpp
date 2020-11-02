//
// Created by Adam Szokalski on 12/12/2019.
//

#include <iostream>

using namespace std;

int T[10000000];

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> T[i];
    }

    int kapusty = 0;
    int roze = 0;
    int best = 1000000;

    int pocz = 0, kon = 0;
    while (T[pocz] == 0 && pocz < n) {
        pocz++;
    }
    kon = pocz;

    while (kon < n) {

        if (roze < k && kon < n) {

            switch (T[kon]) {
                case 1:
                    roze++;
                    break;
                case 0:
                    kapusty++;
                    break;
            }

            kon++;
        } else if (roze == k) {
            best = min(kapusty, best);
            pocz += 1;
            roze -= 1;
            while (T[pocz] == 0 && pocz < n) {
                pocz++;
                kapusty -= 1;
            }
        }
    }

    if (best == 1000000) {
        cout << "NIE" << endl;
    } else {
        cout << best << endl;
    }

    return 0;
}