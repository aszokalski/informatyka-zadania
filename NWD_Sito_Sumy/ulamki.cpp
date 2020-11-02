//
// Created by Adam Szokalski on 09/10/2019.
//

#include <iostream>
#include <vector>

using namespace std;

long long int NWD(long long int a, long long int b) {
    while (b)
        swap(a %= b, b);
    return a;
}

int main() {
    int n;
    cin >> n;

    vector<pair<long long int, long long int>> odp;
    for (long long int i = 0; i < n; ++i) {
        long long int xa, xb, ya, yb;
        cin >> xa >> xb >> ya >> yb;
        long long int a = 0, b = 0;
        a = xa * yb + ya * xb;
        b = xb * yb;
        long long int nwd = NWD(a, b);
        a /= nwd;
        b /= nwd;
        odp.emplace_back(make_pair(a, b));
    }

    for (auto elem : odp) {
        cout << elem.first << " " << elem.second << endl;
    }
    return 0;
}