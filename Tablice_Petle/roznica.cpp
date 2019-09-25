//
// Created by Adam Szokalski on 25/09/2019.
//

#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int a[500001];
    for (int x = 0; x < n; ++x) {
        cin>>a[x];
    }

    int wynik = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = n-1; j >= 0; --j) {
            if(i == j)
                break;
            int roznica = max(a[i] - a[j], a[j] - a[i]);

            if(roznica > wynik)
                wynik = roznica;

        }
    }

    cout << wynik << endl;
}