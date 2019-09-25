#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void swap_elements(vector<int> & v, int x, int y){
    iter_swap(v.begin() + x, v.begin() + y);
}

int main() {
    vector<int> a = {};
    int len = 0;

    cin>> len;

    for (int x = 0; x < len; ++x) {
        int elem = 0;
        cin>> elem;
        a.push_back(elem);
    }

    int i = 0,  k = int(a.size() - 1);

    while(a[i] == 1) { ++i; }
    while(a[k] == 3) {--k;  }

    for (int j = i; j <= k; ++j) {

        switch(a[j]){
            case 1:
                swap_elements(a, j, i);
                j -= 1;
                break;
            case 2:
                break;
            case 3:
                swap_elements(a, j, k);
                j -= 1;
                break;
            default:
                break;
        }

        while(a[i] == 1) { ++i; }
        while(a[k] == 3) {--k;  }

        while(j < i) ++j;
    }

    for (int l : a) {
        cout<< l << " ";
    }

    cout<<endl;


    return 0;
}