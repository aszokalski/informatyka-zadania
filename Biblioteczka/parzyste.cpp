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
    int result = std::count_if(T, T + n, [](int i) { return i % 2 == 0; });
    cout << result << endl;
}