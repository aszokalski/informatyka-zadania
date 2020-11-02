//
// Created by Adam Szokalski on 19.10.2020.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<pair<int, int>> T;
    vector<pair<int, int>> D;
    int n;
    cin >> n;

    T.emplace_back(-numeric_limits<int>::max(), 0);
    D.emplace_back(-numeric_limits<int>::max(), 0);

    for (int i = 1; i <= n; ++i) {
        int elem;
        cin >> elem;

        //wyszukiwanie binarne (większy równy potem - 1)
        auto end = lower_bound(D.begin(), D.end(), make_pair(elem, 0), comp);

        if (end == D.end())
            T.emplace_back(elem, D.back().second), D.emplace_back(elem, i);
        else
            T.emplace_back(elem, (end - 1)->second), *end = make_pair(elem, i);
    }

    cout << D.size() - 1 << endl;

    //propagacja indexami
    vector<int> wyn;
    //0 jest flaga to dla 0 nie dziala. Jak ma dzialac to trzeba zastapic czyms
    for (int curr = D.back().second; T[curr].first != -numeric_limits<int>::max(); curr = T[curr].second)
        wyn.push_back(curr);

    reverse(wyn.begin(), wyn.end());
    for (auto elem : wyn)
        cout << elem << " ";
    cout << "\n";

    return 0;
}
