//
// Created by Adam Szokalski on 07.09.2020.
//

#include<iostream>
#include<algorithm>

using namespace std;

pair<int, char> T[2000];

bool por(pair<int, char> a, pair<int, char> b) {
    return a.first > b.first;
}

int main() {
    int m, n;
    cin >> m >> n;
    m--;
    n--;

    for (int i = 0; i < m + n; ++i) {
        cin >> T[i].first;
        T[i].second = (i < m) ? 'x' : 'y';
    }


    sort(T, T + m + n, por);

    int cost = 0;
    int parts_x = 1;
    int parts_y = 1;

    for (int i = 0; i < m + n; ++i) {
        // cout << T[i].first <<" " << T[i].second <<endl;
        if (T[i].second == 'x') {
            cost += parts_x * T[i].first;
            parts_y++;
        } else {
            cost += parts_y * T[i].first;
            parts_x++;
        }
    }

    cout << cost << endl;
    return 0;
}