//
// Created by Adam Szokalski on 14.09.2020.
//

#include<iostream>
#include <algorithm>

using namespace std;
int T[2000000];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> T[i];
    }

    //logika
    auto a = minmax_element(T, T + n);
    cout << *a.first << " " << *a.second << endl;
    return 0;
}