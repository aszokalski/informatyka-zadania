//
// Created by Adam Szokalski on 19/12/2019.
//

#include <iostream>

using namespace std;

int main() {
    long long int n, w;
    cin >> n >> w;

    long long int x = n;
    while (x <= n && x > 0) {
        int wyr = x * (n - x);

        if (wyr == w) {
            break;
        } else if (wyr < w) {
            x = x / 2;
        } else {
            x = (n / 2) + (x / 2);
        }
    }

    cout << n - x << endl;
    return 0;
}