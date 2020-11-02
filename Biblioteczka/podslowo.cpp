//
// Created by Adam Szokalski on 14.09.2020.
//

#include<iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;
int T[200000];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> T[i];
    }

    //logika
    partial_sum(T, T + n, T);
    auto max_a = max_element(T, T + n);
    for (int i = 0; i < n; ++i) {
        cout << T[i] << endl;
    }
}