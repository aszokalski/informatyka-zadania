//
// Created by Adam Szokalski on 03/03/2020.
//

#include<iostream>

using namespace std;

int W[100];
pair<int, int> M[10001];
int temp[10001];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> W[i];
        M[W[i]] = {1, W[i]};
    }


    for (int i = W[0]; i <= 10000; ++i) {
        int minimal = 1001;
        int min_nominal = 0;
        for (int j = 0; j < n; ++j) {
            int nominal = W[j];

            if ((i - nominal) > 0 && minimal > M[i - nominal].first + 1) {

                minimal = M[i - nominal].first + 1;

                min_nominal = nominal;
            }
        }
        M[i] = {minimal, min_nominal};
        cout << M[i].first << endl;
    }

    int q;
    cin >> q;
    for (int j = 0; j < q; ++j) {
        int kwota;
        cin >> kwota;

        int cnt = 0;
        while (kwota != 0) {
            temp[cnt] = M[kwota].second;
            kwota -= M[kwota].second;
            cnt++;
        }

        cout << cnt << " ";

        for (int i = 0; i < cnt; ++i) {
            cout << temp << " ";
        }

        cout << endl;

    }

    return 0;
}
