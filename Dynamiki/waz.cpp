//
// Created by Adam Szokalski on 03/03/2020.
//

#include <iostream>

using namespace std;

long long T[1000][1000];

int main() {
    //magic
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> T[i][j];
            if (i == 0 && j == 0)
                T[i][j] = T[i][j];
            else if (i == 0 && j > 0)
                T[i][j] = T[0][j - 1] + T[i][j];
            else if (i > 0 && j == 0)
                T[i][j] = T[i - 1][0] + T[i][j];
        }
    }

    for (int i = 1; i < n; ++i)
        for (int j = 1; j < m; ++j)
            T[i][j] = max(T[i - 1][j], T[i][j - 1]) + T[i][j];

    cout << T[n - 1][m - 1] << endl;

    return 0;
}

