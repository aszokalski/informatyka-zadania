//
// Created by Adam Szokalski on 05.10.2020.
//

#include <iostream>
#include <algorithm>

using namespace std;

int M[1001];
int C[1001];


int main() {
    int T[1001][1001];
    int B, n;
    cin >> n >> B;
    for (int i = 1; i <= n; ++i) {
        cin >> M[i];
        cin >> C[i];
    }


    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= B; ++j)

            if (M[i] > j)
                T[i][j] = T[i - 1][j];
            else
                T[i][j] = max(T[i - 1][j], C[i] + T[i - 1][j - M[i]]);


    cout << T[n][B] << "\n";
    return 0;
}