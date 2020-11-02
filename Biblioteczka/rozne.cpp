//
// Created by Adam Szokalski on 14.09.2020.
//

#include<iostream>
#include <algorithm>
#include <iterator>

using namespace std;
int T[200000];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> T[i];
    }

    //logika
    sort(T, T + n);
    cout << distance(T, unique(T, T + n)) << endl;
}