//
// Created by Adam Szokalski on 23/09/2019.
//


#include <iostream>

using namespace std;

int main() {
    long long int n, k, f;
    cin >> n >> k >> f;

    long long int ret = 0;
    for (long long int i = 0; i < n; ++i) {
        long long int wiek;
        cin >> wiek;
        if (wiek > 44) {
            ret += 1;
        }
    }

    cout << ret << endl;
    cout << ((ret * k <= f) ? "PRAWDA" : "FAŁSZ") << endl;

    return 0;
}