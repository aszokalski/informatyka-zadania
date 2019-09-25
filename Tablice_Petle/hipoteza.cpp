//
// Created by Adam Szokalski on 23/09/2019.
//

#include <iostream>
#include <random>
#include <vector>


using namespace std;
using u64 = uint64_t;

unsigned int binpow(unsigned int base, unsigned int e, unsigned int mod) {
    unsigned int ret = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            ret = ret * base % mod;
        base = base * base % mod;
        e >>= 1;
    }
    return ret;
}

/*bool testPierwszosciFermata(unsigned long int n, int dokladnosc=5) {
    if (n < 4)
        return n == 2 || n == 3;

    for (int i = 0; i < dokladnosc; i++) {
        unsigned long int a = 2 + rand() % (n - 3);
        if (binpow(a, n - 1, n) != 1)
            return false;
    }
    return true;
}*/

bool naiwnyTestPierwszosci(unsigned long long n){
    if(n <= 3)
        return true;
    if(n%2 == 0)
        return false;

    for (int i = 3; i <= sqrt(n); i += 2)
        if(n % i == 0)
            return false;
    return true;
}

bool check_composite(u64 n, u64 a, u64 d, int s) {
    u64 x = binpow(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};

bool MillerRabin(u64 n, int iter=1) { // returns true if n is probably prime, else returns false.
    if (n < 4)
        return n == 2 || n == 3;

    int s = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }

    for (int i = 0; i < iter; i++) {
        int a = 2 + rand() % (n - 3);
        if (check_composite(n, a, d, s))
            return false;
    }
    return true;
}

pair<unsigned long int, unsigned long int> hipoteza(unsigned long int n){
    unsigned long int a = n / 2;
    unsigned long int b = a;

    if(a%2 == 0){
        a += 1;
        b -= 1;
    }

    while(!naiwnyTestPierwszosci(a) || !naiwnyTestPierwszosci(b)){
        a += 2;
        b -= 2;
    }

    return make_pair(min(a, b), max(a, b));
}

int main(){
    int n;
    cin >> n;

    vector<unsigned long int> liczby = {};
    for (int i = 0; i < n; ++i) {
        unsigned long int elem;
        cin>> elem;
        liczby.push_back(elem);
    }

    for (int j = 0; j < n; ++j) {
        pair<unsigned long int, unsigned long int> ret = hipoteza(liczby[j]);
        cout <<ret.first << " " << ret.second << endl;
    }

    return 0;
}