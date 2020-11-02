//
// Created by Adam Szokalski on 28/11/2019.
//

//
// Created by Adam Szokalski on 28/11/2019.
//

#include <iostream>
#include <algorithm>

using namespace std;

string T[1000000];


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> T[i];
        swap(T[i][1], T[i][3]);
    }

    stable_sort(T, T + n);
    for (int j = 0; j < n; ++j) {

        swap(T[j][1], T[j][3]);
        cout << T[j] << " ";
    }
    cout << endl;
    return 0;
}