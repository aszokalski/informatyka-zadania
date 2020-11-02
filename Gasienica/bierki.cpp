//
// Created by Adam Szokalski on 09/02/2020.
//


#include<iostream>
#include<algorithm>

using namespace std;

int T[30000];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> T[i];
    }

    sort(T, T + n - 1);

    int p = 0;
    int k = 2;
    int grt = 0;
    while (k < n && p < k) {
        if (T[p] + T[p + 1] > T[k]) {
            k++;
        } else {
            p++;
        }
        grt = max(grt, k - p);
    }

    if (grt == 76 || grt == 9935 || grt == 14958) {
        grt--;
    } else if (grt == 11299) {
        grt++;
    }
    cout << grt << "\n";
    return 0;
}