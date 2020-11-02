//
// Created by Adam Szokalski on 03/03/2020.
//

#include<iostream>

using namespace std;

int nominaly[110];
pair<int, int> T[10010];
int temp[10010];

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> nominaly[i];
    }

    T[0] = {0, 0};

    for (int j = 1; j < 10000 + 1; ++j) {
        T[j] = {10010, 0};
        for (int i = 0; i < n; ++i) {
            int nominal = nominaly[i];
            if (j - nominal >= 0 && (T[j - nominal].first + 1) < T[j].first)
                T[j] = {T[j - nominal].first + 1, nominal};
        }
    }

    int q;
    cin >> q;
    for (int j = 0; j < q; ++j) {
        int kwota;
        cin >> kwota;

        if (T[kwota].first == 10010) {
            cout << -1 << endl;
        } else {
            int cnt = 0;
            while (kwota != 0) {
                temp[cnt] = T[kwota].second;
                kwota -= T[kwota].second;
                cnt++;
            }

            cout << cnt << " ";

            for (int i = cnt - 1; i >= 0; --i) {
                cout << temp[i] << " ";
            }

            cout << endl;
        }
    }


    return 0;
}