//
// Created by Adam Szokalski on 22/04/2020.
//

#include<iostream>
#include <vector>

using namespace std;

int T[1000000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> stos;
    int n;
    cin >> n;

    int q;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        string operacja;
        cin >> operacja;

        if (operacja == "zdejmij") {
            int a = stos.back();
            stos.pop_back();
            T[a] = 0;
        } else {
            int x;
            cin >> x;
            if (operacja == "odloz") {
                stos.push_back(x);
                T[x] = stos.size();
            } else if (operacja == "pytaj") {
                int i = T[x];
                if (i == 0) { cout << -1 << endl; }
                else { cout << stos.size() - i << endl; }
            }
        }
    }
    return 0;
}