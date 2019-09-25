//
// Created by Adam Szokalski on 25/09/2019.
//
#include <iostream>
#include<string>

using namespace std;

int main(){
    int arr[3];
    cin>>arr[0]>>arr[1]>>arr[2];

    cout<< arr[0] << " " << arr[1] << " " << arr[2] << endl;
    cout<< arr[2] << " " << arr[1] << " " << arr[0] << endl;

    return 0;
}