//
// Created by Adam Szokalski on 21.09.2020.
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


int main() {
    Heap h = Heap({});
    int n;
    cin >> n;
    int first, second;
    for (int i = 0; i < n - 1; i++) {
        cin >> first >> second;
        if (first == 1) {
            h.insert(second);
        } else {
            while (h.size() >= second && h.size() > 0) {
                h.eraseRoot();
            }
        }
    }

    cin >> first >> second;

    if (h.size() >= second) {
        cout << h.sum() << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}