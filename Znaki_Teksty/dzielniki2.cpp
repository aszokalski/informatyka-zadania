//
// Created by Adam Szokalski on 09/10/2019.
//

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

long long int gcd(long long int a, long long int b) {
    while (b)
        swap(a %= b, b);
    return a;
}

void dzielniki(long long int a, long long int b) {
    long long int n = 0;
    long long int o_a = 0, o_b = 0;
    do {
        o_a = a;
        o_b = b;
        n = gcd(a, b);
        a /= n;
        b /= n;
        b /= gcd(b, n);
    } while (a != o_a && b != o_b);

    cout << a << " " << b << endl;
}

int main() {
    vector<pair<long long int, long long int>> inp;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        long long int elem1, elem2;
        cin >> elem1 >> elem2;
        inp.emplace_back(elem1, elem2);
    }

    for (auto args : inp) {
        dzielniki(args.first, args.second);
    }

    return 0;
}