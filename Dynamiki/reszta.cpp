//
// Created by Adam Szokalski on 03/03/2020.
//

#include<iostream>

using namespace std;

int nominaly[1000010];
int T[1000010];

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int k, n;
    cin >> k >> n;
    for (int i = 0; i < n; ++i) {
        cin >> nominaly[i];
    }


    for (int j = 1; j < k + 1; ++j) {
        T[j] = 1000001;
        for (int i = 0; i < n; ++i) {
            int nominal = nominaly[i];
            if (j - nominal >= 0)
                T[j] = min(T[j], T[j - nominal] + 1);
        }
    }

    if (k == 0)
        cout << 0 << endl;
    else if (T[k] > 0 && T[k] < 1000001)
        cout << T[k] << endl;
    else
        cout << "NIE" << endl;


    return 0;
}