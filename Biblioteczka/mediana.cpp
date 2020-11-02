//
// Created by Adam Szokalski on 14.09.2020.
//

#include<iostream>
#include <algorithm>

using namespace std;
int T[199999];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> T[i];
    }

    //logika
    nth_element(T, T + n / 2, T + n);
    cout << T[n / 2] << endl;
    return 0;
}