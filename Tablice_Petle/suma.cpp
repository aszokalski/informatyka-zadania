//
// Created by Adam Szokalski on 25/09/2019.
//

#include <iostream>
#include <climits>

using namespace std;

int main(){
    int n, y;
    int n_min = INT_MAX, n_max = INT_MIN;
    cin>>y;
    for (int x = 0; x < y; ++x) {
        cin>>n;
        n_min = min(n , n_min);
        n_max = max(n, n_max);
    }

    int wynik = n_max - n_min;

    cout << wynik << endl;
}