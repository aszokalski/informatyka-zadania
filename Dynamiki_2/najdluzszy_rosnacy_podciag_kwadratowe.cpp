//
// Created by Adam Szokalski on 19.10.2020.
//

#include <iostream>
#include <vector>

using namespace std;

int T[500000][2];

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> T[i][0];
        T[i][1] = 0;
        for (int j = i - 1; j >= 0; --j)
            if (T[j][0] < T[i][0] && T[j][1] > T[i][1])
                T[i][1] = T[j][1];
        T[i][1]++;
    }
    cout << T[n][1] << endl;

    //Propagacja (indexami)
    int me = n;
    vector<int> wyn;
    for (int i = n - 1; i >= 0; --i)
        if (T[i][1] < T[me][1] && T[i][0] < T[me][0])
            wyn.insert(wyn.begin(), me), me = i;

    reverse(wyn.begin(), wyn.end());
    for (auto elem : wyn)
        cout << elem << " ";
    cout << "\n";
    return 0;
}
