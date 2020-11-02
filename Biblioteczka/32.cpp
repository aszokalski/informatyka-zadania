//
// Created by Adam Szokalski on 16.09.2020.
//

#include<iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        if (i % 2)
            cout << i << " ";
    }
    cout << endl;
    return 0;
}