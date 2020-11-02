//
// Created by Adam Szokalski on 23/01/2020.
//

#include<iostream>
#include<algorithm>

using namespace std;

long long T[1000000];
int O[100000];

int count(long long x, int n) {

    int p = 0;
    int k = n;
    int i = 0;
    int old_i = -1;
    while (i != old_i && p <= k) {

        old_i = i;
        i = p + (k - p) / 2;
        if (T[i] < x) {

            p = i + 1;
        } else if (T[i] > x) {

            k = i - 1;

        } else {

            k = i;
        }
    }

    int first = i;

    p = 0;
    k = n;
    i = 0;
    old_i = -1;
    while (i != old_i && p <= k) {

        old_i = i;
        i = p + (k - p + 1) / 2;

        if (T[i] < x) {

            p = i + 1;

        } else if (T[i] > x) {

            k = i - 1;

        } else {

            p = i;
        }
    }

    int last = i;
    if (T[first] != x && T[last] != x) {
        return 0;
    }
    return last - first + 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> T[i];
    }

    sort(T, T + n);

    int q;
    cin >> q;
    for (int j = 0; j < q; ++j) {
        long long question;
        cin >> question;
        if (n == 0) {
            cout << 0 << "\n";
        } else {
            cout << count(question, n - 1) << "\n";
        }
    }
    return 0;
}
