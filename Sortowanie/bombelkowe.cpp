//
// Created by Adam Szokalski on 16/10/2019.
//
#include <iostream>
#include <vector>

using namespace std;

void bombel(int T[], int n) {
    int zamiany = 0;
    do {
        zamiany = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (i[T] > (i + 1)[T]) {
                swap(i[T], (i + 1)[T]);
                zamiany++;
            }
        }
    } while (zamiany > 0);
}

int main() {
    int tab[1000 * 1000];
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> i[tab];
    }
    bombel(tab, n);
    for (int j = 0; j < n; ++j) {
        cout << j[tab] << " ";
    }

    cout << "\n";
    return 0;
}