//
// Created by Adam Szokalski on 28/11/2019.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

pair<string, int> czlonkowie[100];

bool por(pair<string, int> a, pair<string, int> b) {
    return a.second > b.second;
}

int main() {
    int n;
    cin >> n;


    for (int i = 0; i < n; ++i) {
        cin >> czlonkowie[i].first >> czlonkowie[i].second;
    }

    stable_sort(czlonkowie, czlonkowie + n, por);

    int best = czlonkowie[0].second;
    int i = 0;

    while (czlonkowie[i].second == best && i < n) {
        cout << czlonkowie[i].first << endl;
        ++i;
    }
    return 0;
}