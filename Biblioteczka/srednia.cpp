//
// Created by Adam Szokalski on 14.09.2020.
//

#include<iostream>
#include <numeric>
#include <iomanip>

using namespace std;
int T[200000];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> T[i];
    }

    //logika
    float result = accumulate(T, T + n, 0.0f) / float(n);
    cout << setprecision(7) << fixed << result;
    return 0;
}