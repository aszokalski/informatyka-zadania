//
// Created by Adam Szokalski on 16/10/2019.
//
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> A;
    vector<vector<int>> Sum;
    for (int i = 0; i < n; ++i) {
        vector<int> row;
        vector<int> zeros;
        for (int j = 0; j < m; ++j) {
            int elem;
            cin >> elem;
            row.push_back(elem);
            zeros.push_back(0);
        }
        A.push_back(row);
        Sum.push_back(zeros);
    }


    Sum[0][0] = A[0][0];

    for (int i = 1; i < n; ++i) {
        Sum[i][0] = Sum[i - 1][0] + A[i][0];
    }

    for (int i = 1; i < m; ++i) {
        Sum[0][i] = Sum[0][i - 1] + A[0][i];
    }


    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            Sum[i][j] = Sum[i - 1][j] + Sum[i][j - 1] - Sum[i - 1][j - 1] + A[i][j];
        }
    }

    int k;
    cin >> k;
    vector<int> Answ;
    for (int l = 0; l < k; ++l) {
        int ax, bx, ay, by;
        cin >> ax >> bx >> ay >> by;
        ax -= 1;
        bx -= 1;
        ay -= 1;
        by -= 1;
        int sf = Sum[ay][by];

        if (ax - 1 >= 0)
            sf -= Sum[ax - 1][by];
        if (bx - 1 >= 0)
            sf -= Sum[ay][bx - 1];
        if (ax - 1 >= 0 && bx - 1 >= 0)
            sf += Sum[ax - 1][bx - 1];

        Answ.push_back(sf);
    }

    for (auto a : Answ) {
        cout << a << "\n";
    }


    return 0;
}