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

string dodawanie(string a, string b) {
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


    return res;
}

int index(string s, char c) {
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == c) {
            return i;
        }
    }
    return -1;
}

int main() {
    int N;
    cin >> N;
    string res = "+0,0";

    for (int i = 0; i < N; ++i) {
        string line;
        cin >> line;
        char line_sign = line[0];
        char res_sign = res[0];

        if (line_sign == '-' || line_sign == '+') {
            line = line.substr(1);
        } else {
            line_sign = '+';
        }

        if (res_sign == '-' || res_sign == '+') {
            res = res.substr(1);
        } else {
            res_sign = '+';
        }

        //wyrownanie
        int res_pivot = index(res, ',');
        int line_pivot = index(line, ',');

        string new_line = "";
        string new_res = "";

        if (res_pivot > line_pivot) {
            for (int j = 0; j < res_pivot - line_pivot; ++j) {
                new_line += '0';
            }

        } else if (res_pivot < line_pivot) {
            for (int j = 0; j < line_pivot - res_pivot; ++j) {
                new_res += '0';
            }
        }

        for (auto c : line) {
            if (c != ',') {
                new_line += c;
            }
        }

        for (auto c : res) {
            if (c != ',') {
                new_res += c;
            }
        }

        int max_size = max(new_res.size(), new_line.size());

        while (new_line.size() < max_size) {
            new_line += '0';
        }
        while (new_res.size() < max_size) {
            new_res += '0';
        }

        while (new_res[0] == '0' && new_res.size() > 1) {
            new_res = new_res.substr(1);
        }
        while (new_line[0] == '0' && new_line.size() > 1) {
            new_line = new_line.substr(1);
        }

        if (line_sign != '+') {
            new_line = line_sign + new_line;
        }
        if (res_sign != '+') {
            new_res = res_sign + new_res;
        }

        string product = dodawanie(new_res, new_line);
        int new_pivot = (product.size()) - (max_size - line_pivot);
        while (product.size() - 1 < new_pivot) {
            string end = product.substr(1);
            product = {product[0], '0'};
            product += end;
        }
        string fin_product = "";
        for (int k = 0; k < product.size(); ++k) {
            if (k == new_pivot) {
                fin_product += ',';
            }
            fin_product += product[k];
        }

        if (fin_product[0] == ',') {
            fin_product = '0' + fin_product;
        }
        if (fin_product[0] == '-' && fin_product[1] == ',') {
            string end = fin_product.substr(1);
            fin_product = {fin_product[0], '0'};
            fin_product += end;
        }
        while (fin_product[fin_product.size() - 1] == '0') {
            fin_product = fin_product.substr(0, fin_product.size() - 1);
        }
        while (fin_product[fin_product.size() - 1] == ',') {
            fin_product = fin_product.substr(0, fin_product.size() - 1);
        }

        res = fin_product;
    }

    cout << res << endl;


    return 0;
}