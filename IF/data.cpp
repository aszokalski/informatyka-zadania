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

bool prawidlowa(int d, int m, int y){
    if (m < 1 || m > 12)
        return false;
    if (d < 1 || d > 31)
        return false;

//    if(y == 1582 && m == 10 && d > 4 && d < 15){
//        cout << "NIE" << endl;
//        return 0;
//    }

    if (m == 2)
    {
        if (przestepny(y))
            return (d <= 29);
        else
            return (d <= 28);
    }

    if (m == 4 || m == 6 ||
        m == 9 || m == 11)
        return (d <= 30);

    return true;
}

int main(){
    int d, m, y;
    cin >> d >> m >> y;
    if(prawidlowa(d, m, y)){
        cout<<"TAK"<<endl;
    } else{
        cout<<"NIE"<<endl;
    }
    return 0;
}
