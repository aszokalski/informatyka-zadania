//
// Created by Adam Szokalski on 25/09/2019.
//
#include <iostream>
#include<vector>


using namespace std;

int main(){
    int d;
    cin>>d;
    vector<int> wyniki={};

    for (int i = 0; i < d; ++i) {
        int n;
        cin>>n;

        int suma = 0;
        for (int j = 0; j < n; ++j) {
            int kasztany;
            cin>>kasztany;
            suma += kasztany;
        }

        wyniki.push_back(suma);
    }

    for (auto elem : wyniki) {
        cout << elem << endl;
    }
    return 0;
}