//
// Created by Adam Szokalski on 22/04/2020.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<string> stos;
    int n;
    cin >> n;
    stos.emplace_back("");

    for (int i = 0; i < n; ++i) {
        string operacja;
        cin >> operacja;

        if (operacja == "backspace") {
            string nowy = stos.back();
            nowy.pop_back();
            stos.push_back(nowy);
        } else if (operacja == "dopisz") {
            char param;
            cin >> param;
            stos.push_back(stos.back() + param);
        } else if (operacja == "ctrl-z") {
            int param;
            cin >> param;
            stos.push_back(stos[stos.size() - param - 1]);
        }

        if (stos.back().empty()) { cout << "." << endl; }
        else { cout << stos.back().back() << endl; }

    }

    cout << stos.back() << endl;
    return 0;
}

