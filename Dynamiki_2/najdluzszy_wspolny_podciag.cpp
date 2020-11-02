//
// Created by Adam Szokalski on 02.11.2020.
//

#include<iostream>
#include<vector>

using namespace std;

int A[100];
int B[100];
int T[100][100];

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
        cin >> A[i];
    for (int i = 1; i <= m; ++i)
        cin >> B[i];

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (A[i] == B[j])
                T[i][j] = T[i - 1][j - 1] + 1;
            else
                T[i][j] = max(T[i][j - 1], T[i - 1][j]);

    cout << T[n][m] << endl;

    int i = n, j = m;
    int curr;
    bool pass = false;
    vector<int> wyn;

    while (i != 0) {
        if (T[i][j] == T[i - 1][j]) {
            if (pass)
                wyn.push_back(curr), pass = false;
            i--;
        } else {
            curr = A[i];
            pass = true;
            j--;
        }
    }

    reverse(wyn.begin(), wyn.end());

    for (auto e : wyn)
        cout << e << " ";

    cout << endl;

    return 0;
}