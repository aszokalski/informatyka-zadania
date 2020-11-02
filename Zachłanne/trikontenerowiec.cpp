//
// Created by Adam Szokalski on 30.09.2020.
//

#include<iostream>
#include<vector>
#include <limits>
#include <numeric>

using namespace std;

double inf = numeric_limits<double>::infinity();

class Heap {
private:
    void heapUp(int x) {
        while (base[x / 2] > base[x]) {
            swap(base[x / 2], base[x]);
            x /= 2;
        }
    }

    void heapDown(int x) {
        while (2 * x <= base.size() - 1) {
            int son = 2 * x;

            if (son + 1 <= base.size() && base[son + 1] < base[son])

                son = son + 1;

            if (base[son] >= base[x]) break;
            swap(base[x], base[son]);
            x = son;
        }
    }


public:
    vector<int> base;

    Heap(vector<int> v) {
        v.insert(v.begin(), -inf);
        base = v;
    }

    void insert(int x) {
        base.push_back(x);
        heapUp(base.size() - 1);
    }

    void eraseRoot() {
        base[1] = base[base.size() - 1];
        base.pop_back();

        heapDown(1);
    }

    int minimum() {
        return base[1];
    }

    int size() {
        return base.size() - 1;
    }

    int sum() {
        return accumulate(base.begin() + 1, base.end(), 0);
    }
};

bool por(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second)
        return a.first > b.first;
    return a.second > b.second;
}

pair<int, int> T[1000 * 1000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m, n;
    cin >> m >> n;

    for (int i = 0; i < n; ++i)
        cin >> T[i].first >> T[i].second;

    sort(T, T + n, por);

    Heap h = Heap({});
    int level = m + 1;
    for (int i = 0; i < n; ++i) {
        if (T[i].second > m) continue;

        if (h.size() < m && T[i].second < level) {
            level--;
            h.insert(T[i].first);
        } else if (T[i].first > h.minimum()) {
            h.eraseRoot();
            h.insert(T[i].first);
        }
    }

    cout << h.sum() << "\n";
    return 0;
}