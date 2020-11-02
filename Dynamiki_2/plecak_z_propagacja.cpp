//
// Created by Adam Szokalski on 12.10.2020.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 100 + 7;
const int MAXW = 10 * 1000 + 7;

int dp[MAXN][MAXW];
int c[MAXN], w[MAXN];
int n, B;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> n >> B;
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    for (int i = 1; i <= n; i++)
        cin >> c[i];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= B; j++) {
            if (w[i] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j - w[i]] + c[i], dp[i - 1][j]);
        }
    }
    cout << dp[n][B] << '\n';
    vector<int> wyn;
    int i = n, j = B;
    while (j > 0 && i > 0) {
        if (dp[i][j] != dp[i - 1][j])
            wyn.push_back(i), j -= w[i];
        i--;
    }
    cout << wyn.size() << '\n';
    for (auto &w : wyn)
        cout << w << ' ';
    return 0;
}