#include <bits/stdc++.h>

using namespace std;

pair<int, int> mala = {97, 122};
pair<int, int> duza = {65, 90};
pair<int, int> liczba = {48, 57};

int n;
vector<int> cechy;
string s;


int spacje() {
    return count(s.begin(), s.end(), ' ');
}

int numer() {
    bool k = false;
    int c = 0;
    for (auto i:s) {
        if (liczba.first <= i && i <= liczba.second) {
            if (!k) {
                k = true;
                c++;
            }
        } else
            k = false;
    }

    return c;
}

bool palindrom(string &o) {
    for (int i = 0; i < int(o.size() / 2 + 1); ++i) {
        if (tolower(o[i]) != tolower(o.end()[-(i + 1)])) {
            return false;
        }
    }
    return true;
}

pair<int, int> slowo() {
    bool k = false;
    int c = 0, p = 0;
    string word;

    for (auto i:s) {
        if ((mala.first <= i && i <= mala.second) || (duza.first <= i && i <= duza.second)) {
            if (!k) {
                k = true;
                c++;
            }

            word += i;
        } else if (k) {
            if (palindrom(word))
                p++;

            word = "";
            k = false;
        }
    }

    if (k) {
        if (palindrom(word))
            p++;
    }

    return make_pair(c, p);
}

int sentance() {
    bool k = false;
    int o = 0;

    for (auto i: s) {
        if (i == '.' && k) {
            o++;
            k = false;
        } else if (!k && ((mala.first <= i && i <= mala.second) || (duza.first <= i && i <= duza.second))) {
            k = true;
        }
    }

    return o;
}


int main() {
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        cechy.push_back(a);
    }

    for (int j = 0; j < 2; ++j) {
        getline(cin, s);
    }

    for (auto i: cechy) {
        if (i == 1)
            cout << spacje() << " ";
        if (i == 2)
            cout << numer() << " ";
        if (i == 3)
            cout << slowo().first << " ";
        if (i == 4)
            cout << sentance() << " ";
        if (i == 5)
            cout << slowo().second << " ";
    }

}