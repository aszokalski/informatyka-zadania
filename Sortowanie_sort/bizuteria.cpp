//
// Created by Adam Szokalski on 28/11/2019.
//

#include <iostream>
#include <algorithm>

using namespace std;

string T[150];

bool por(string a, string b) {
    if (a.size() == b.size()) {
        return a < b;
    }
    return a.size() < b.size();
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> T[i];
    }

    stable_sort(T, T + n, por);

    for (int j = 0; j < n; ++j) {
        cout << T[j] << endl;
    }
    return 0;
}