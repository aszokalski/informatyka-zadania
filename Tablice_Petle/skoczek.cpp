//
// Created by Adam Szokalski on 24/09/2019.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int NWD(int a, int b){
    while(b){
        swap(a%=b, b);
    }
    return a;
}

bool skoczek(){
    int k, n, a, b, x, y;
    cin>> k >> n >> a >> b >> x >> y;

    int skok = NWD(k, n);

    k /= skok;
    n /= skok;
    x -= a;
    y -= b;

    if((x% skok) || (y% skok)){
        return 0;
    } else if(!(k % 2)|| !(n % 2)){
        return 1;
    } else if(!((x+y)%(2*skok))){
        return 1;
    } else {
        return 0;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<bool> res;
    for (int i = 0; i < n; ++i) {
        res.push_back(skoczek());

    }

    for (int j = 0; j < n; ++j) {
        switch(res[j]){
            case 1:
                cout<<"TAK"<<endl;
                break;
            case 0:
                cout<<"NIE"<<endl;
                break;
        }
    }

    return 0;
}