//
// Created by Adam Szokalski on 25/09/2019.
//
#include <iostream>

using namespace std;

bool przestepny(int y) {
    return (((y % 4 == 0) &&
             (y % 100 != 0)) ||
            (y % 400 == 0));
}

int main(){
    int rok;
    cin>>rok;
    if(przestepny(rok)){
        cout<<"TAK"<<endl;
    } else{
        cout<<"NIE"<<endl;
    }
}