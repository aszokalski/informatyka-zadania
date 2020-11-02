//
// Created by Adam Szokalski on 05.10.2020.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int M[101];
int C[101];

int main() {
    int T[101][10001];
    int n, B;
    cin >> n >> B;
    for (int i = 1; i <= n; ++i)
        cin >> M[i];
    for (int i = 1; i <= n; ++i)
        cin >> C[i];


    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= B; ++j)
            if (M[i] > j)
                T[i][j] = T[i - 1][j];
            else
                T[i][j] = max(T[i - 1][j], C[i] + T[i - 1][j - M[i]]);

    vector<int> wyn;
    int i = n, j = B;
    while (j > 0 && i > 0) {
        if (T[i][j] != T[i - 1][j])
            wyn.push_back(i), j -= M[i];
        i--;
    }

    cout << T[n][B] << "\n";
    cout << wyn.size() << '\n';
    sort(wyn.begin(), wyn.end());
    for (auto &w : wyn)
        cout << w << ' ';

    return 0;
}