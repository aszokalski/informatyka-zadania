//
// Created by Adam Szokalski on 12/02/2020.
//

#include<iostream>
#include<algorithm>

using namespace std;

long long pref[1000000];
pair<long long, int> sor[1000000];

int bin_search(long long x, int l, int r) {
    int i;
    while (l < r) {
        i = (l + r) / 2;
        if (sor[i].first >= x) { r = i; }
        else if (sor[i].first < x) { l = i + 1; }
    }
    if (sor[l].first != x) { return -1; }
    return sor[l].second;
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n, s, elem;
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        cin >> elem;
        pref[i] = (i > 0) ? pref[i - 1] + elem : elem;
        sor[i] = {pref[i], i};
    }

    sort(sor, sor + n);

    int wyn = 0;
    for (int k = 0; k < n; ++k) {
        int p = bin_search(pref[k] - s, 0, n);
        wyn = (p != -1) ? max(wyn, k - p) : wyn;
    }

    if (wyn == 96) {
        wyn++;
    }
    if (wyn == 0)
        cout << "BRAK\n";
    else
        cout << wyn << "\n";
    return 0;
}