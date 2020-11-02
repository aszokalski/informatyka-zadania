#include <iostream>

using namespace std;

int main() {
    int k;
    cin >> k;

    int wynik = 0;
    int power = 1;
    for (int i = 0; i <= k; ++i) {
        int ilosc;
        cin >> ilosc;
        wynik += power * ilosc;
        power *= 2;
    }

    cout << wynik + 1 << endl;
    return 0;
}

