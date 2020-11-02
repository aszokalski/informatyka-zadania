//
// Created by Adam Szokalski on 22/04/2020.
//

#include<iostream>
#include <vector>

using namespace std;


int strtoi(string x) {
    try {
        return stoi(x);
    } catch (const std::exception &e) {
        return -1;
    }
}

int main() {
    vector<long long> T;

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string elem;
        cin >> elem;

        int num = strtoi(elem);

        if (num != -1) {
            T.push_back(num);
        } else {
            long long b = T.back();
            T.pop_back();
            long long a = T.back();
            T.pop_back();

            switch (elem[0]) {
                case '+':
                    T.push_back(a + b);
                    break;
                case '-':
                    T.push_back(a - b);
                    break;
                case '*':
                    T.push_back(a * b);
                    break;
                case '/':
                    T.push_back(a / b);
                    break;
                default:
                    break;
            }
        }
    }

    cout << T.back() << endl;
    return 0;
}