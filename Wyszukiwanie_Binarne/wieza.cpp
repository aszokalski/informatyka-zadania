//
// Created by Adam Szokalski on 25/01/2020.
//

#include<iostream>
#include<algorithm>

using namespace std;

int S[500000];
pair<int, int> M[500000];
int W[500000];

int find_first_larger(int x, int p, int k) {
    int i;
    while (p < k) {
        i = (p + k) / 2;

        if (M[i].first <= x) { p = i + 1; }
        else if (M[i].first > x) { k = i; }

        if (M[p].first == M[k].first) {
            break;
        }
    }
    return p;
}

void climb(int n, int p, int k) {
    int i;
    for (i = 0; i < n; ++i) {

        int f = find_first_larger(S[i], p, k);

        if (M[f].first <= S[i] || f > k) {
            break;
        } else {
            for (int j = p; j < f; ++j) {

                W[M[j].second] = i;
            }

            p = f;
        }
    }


    for (int l = p; l <= k; ++l) {
        if (M[l].first > S[n - 1]) {
            W[M[l].second] = n;
        } else {
            W[M[l].second] = i;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        cin >> S[i];
    }

    for (int j = 0; j < m; ++j) {
        cin >> M[j].first;
        M[j].second = j;
    }

    sort(M, M + m);
    climb(n, 0, m - 1);

    for (int k = 0; k < m; ++k) {
        cout << W[k] << " ";
    }
    cout << "\n";
    return 0;
}