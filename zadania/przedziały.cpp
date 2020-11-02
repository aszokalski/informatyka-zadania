//
// Created by Adam Szokalski on 07.09.2020.
//

#include<iostream>
#include<algorithm>

using namespace std;

pair<int, int> T[200000];

bool por(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> T[i].first;
        cin >> T[i].second;
    }

    sort(T, T + n, por);

    int score = 1;
    int last = 0;
    for (int i = 1; i < n; ++i) {
        if (T[last].second <= T[i].first) {
            score++;
            last = i;
        }
    }

    cout << score << endl;
}