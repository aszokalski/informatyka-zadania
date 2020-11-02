//
// Created by Adam Szokalski on 05.10.2020.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int M[100];
int C[100];

int main() {
    int n, B;
    cin >> n >> B;
    for (int i = 0; i < n; ++i)
        cin >> M[i];
    for (int i = 0; i < n; ++i)
        cin >> C[i];

    vector<int> X(B + 1);
    vector<int> Y;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= B; ++j)
            if (M[i] > j) {
                Y.push_back(X[j]);
            } else {
                Y.push_back(max(X[j], C[i] + X[j - M[i]]));
            }


        copy(Y.begin(), Y.end(), X.begin());
        Y.clear();
    }

    cout << X[B] << "\n";
    return 0;
}