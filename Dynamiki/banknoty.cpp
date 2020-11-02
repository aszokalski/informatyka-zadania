//
// Created by Adam Szokalski on 03/03/2020.
//

#include<iostream>

using namespace std;

pair<int, int> nominaly[210];
int T[20010];
int I[20010][210];

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> nominaly[i].first;
    for (int i = 0; i < n; ++i)
        cin >> nominaly[i].second;

    int k;
    cin >> k;
    for (int j = 1; j < k + 1; ++j) {

        T[j] = 20010;
        int best = -1;
        for (int i = 0; i < n; ++i) {
            int nominal = nominaly[i].first;
            int ilosc = nominaly[i].second;
            if (j - nominal >= 0 && (T[j - nominal] + 1) < T[j] && (I[j - nominal][i] + 1) <= ilosc) {
                T[j] = (T[j - nominal] + 1);
                best = i;
            }
        }

        if (best >= 0) {
            for (int l = 0; l < n; ++l)
                I[j][l] = I[j - nominaly[best].first][l];
            I[j][best] = (I[j - nominaly[best].first][best] + 1);
        }


    }

    cout << T[k] << endl;
    for (int m = 0; m < n; ++m) {
        cout << I[k][m] << " ";
    }
    cout << endl;


    return 0;
}