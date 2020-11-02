//
// Created by Adam Szokalski on 12/11/2019.
//

#include <iostream>
#include <string>

using namespace std;

bool is_bigger(string a, string b) {
    if (a.size() > b.size()) {
        return true;
    } else if (a.size() < b.size()) {
        return false;
    } else {
        for (int i = 0; i < a.size(); ++i) {
            if (int(a[i] - '0') > int(b[i] - '0')) {
                return true;
            } else if (int(a[i] - '0') < int(b[i] - '0')) {
                return false;
            }
        }
        return false;
    }
}

int main() {
    string a, b;
    cin >> a;
    cin >> b;

    bool a_neg = false;
    bool b_neg = false;
    bool res_neg = false;

    if (a[0] == '-') {
        a = a.substr(1);
        a_neg = true;
    }

    if (b[0] == '-') {
        b = b.substr(1);
        b_neg = true;
    }


    if (is_bigger(b, a)) {
        swap(a, b);
        swap(a_neg, b_neg);
    }

    if (a_neg && !b_neg) {
        a_neg = false;
        b_neg = true;
        res_neg = true;
    }

    int len_a = a.size();
    int len_dif = len_a - b.size();
    string res = a;
    int rem = 0;
    for (int i = len_a - 1; i >= 0; --i) {
        int elem_a = int(a[i]) - '0';
        int elem_b = 0;
        if (i - len_dif >= 0)
            elem_b = int(b[i - len_dif]) - '0';
        int old_rem = rem;

        if ((a_neg && b_neg) || (!a_neg && !b_neg)) {

            rem = ((elem_a + elem_b + old_rem) >= 10) ? 1 : 0;
            res[i] = char((elem_a + elem_b + old_rem) - (10 * rem) + '0');
        } else if (a_neg || b_neg) {

            rem = ((elem_a - elem_b + old_rem) < 0) ? -1 : 0;

            res[i] = char((elem_a - elem_b + old_rem) + (10 * -rem) + '0');

        }
    }


    if (rem != 0)
        res = '1' + res;

    while (res[0] == '0') {
        if (res.size() == 1) {
            res = "0";
            break;
        }
        res = res.substr(1);
    }

    if ((a_neg || (a_neg && b_neg || res_neg)) && res != "0") {
        res = '-' + res;
    }


    cout << res << endl;

    return 0;
}