#include<iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s[n];
    bool plus[n];
    int pos = 0;
    int com[n];
    int after_com = 100;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        if (s[i][0] == '-') { plus[i] = false; }
        if (s[i][0] == '+') {
            plus[i] = true;
            pos++;
        }
        if (s[i][0] != '-' && s[i][0] != '+') {
            plus[i] = true;
            pos++;
        }
        com[i] = -1;
        for (int q = 0; q < s[i].length(); q++) {
            if (s[i][q] == ',' || s[i][q] == '.') {
                com[i] = q;
                break;
            }
        }

    }
    int t[pos][200];
    int ta[n - pos][200];
    for (int i = 0; i < 200; i++) {
        for (int a = 0; a < n; a++) {
            if (a < pos || a == 0) { t[a][i] = 0; }
            if (a < n - pos || a == 0) { ta[a][i] = 0; }
        }
    }

    int neg_num = 0;
    int plus_num = 0;

    for (int i = 0; i < n; i++) {
        if (plus[i]) {
            if (com[i] == -1) {
                for (int q = s[i].length() - 1; q >= 0; q--) {
                    if (s[i][s[i].length() - 1 - q] == '+' || s[i][s[i].length() - 1 - q] == '-') { continue; }
                    t[plus_num][100 - q] = (int) s[i][s[i].length() - 1 - q] - '0';
                }
            } else {
                for (int q = com[i] - 1; q >= 0; q--) {
                    if (s[i][com[i] - 1 - q] == '+' || s[i][com[i] - 1 - q] == '-') { continue; }
                    t[plus_num][100 - q] = (int) s[i][com[i] - 1 - q] - '0';
                }
                for (int q = 1; q < s[i].length() - com[i]; q++) {
                    if (s[i][com[i] + q] == '+' || s[i][com[i] + q] == '-') { continue; }
                    t[plus_num][100 + q] = (int) s[i][com[i] + q] - '0';
                }
            }
            plus_num++;
        } else {
            if (com[i] == -1) {
                for (int q = s[i].length() - 1; q >= 0; q--) {
                    if (s[i][s[i].length() - 1 - q] == '+' || s[i][s[i].length() - 1 - q] == '-') { continue; }
                    ta[neg_num][100 - q] = (int) s[i][s[i].length() - 1 - q] - '0';
                }
            } else {
                for (int q = com[i] - 1; q >= 0; q--) {
                    if (s[i][com[i] - 1 - q] == '+' || s[i][com[i] - 1 - q] == '-') { continue; }
                    ta[neg_num][100 - q] = (int) s[i][com[i] - 1 - q] - '0';
                }
                for (int q = 1; q < s[i].length() - com[i]; q++) {
                    if (s[i][com[i] + q] == '+' || s[i][com[i] + q] == '-') { continue; }
                    ta[neg_num][100 + q] = (int) s[i][com[i] + q] - '0';
                }
            }
            neg_num++;
        }
    }

    int t1[200];
    int ta1[200];
    for (int i = 199; i > 0; i--) {
        if (pos > 0) {
            int sum = 0;
            for (int a = 0; a < pos; a++) {
                sum = sum + t[a][i];
            }
            if (sum >= 10) {
                t[0][i - 1] = t[0][i - 1] + (sum - (sum % 10)) / 10;
                sum = sum % 10;
            }
            t1[i] = sum;
        }
        if (n - pos > 0) {
            int sum = 0;
            for (int a = 0; a < n - pos; a++) {
                sum = sum + ta[a][i];
            }
            if (sum >= 10) {
                ta[0][i - 1] = ta[0][i - 1] + (sum - (sum % 10)) / 10;
                sum = sum % 10;
            }
            ta1[i] = sum;
        }
    }

    bool first_larger = false;
    if (pos > 0 && n - pos > 0) {
        for (int i = 0; i < 200; i++) {
            if (t1[i] > ta1[i]) {
                first_larger = true;
                break;
            }
            if (t1[i] < ta1[i]) {
                first_larger = false;
                break;
            }
            if (i == 199) {
                cout << "0\n";
                return 0;
            }
        }
    } else if (pos > 0) { first_larger = true; }
    if (pos > 0 && n - pos > 0) {
        if (first_larger) {
            int suma = 0;
            for (int i = 199; i >= 0; i--) {
                if (t1[i] - ta1[i] >= 0) {
                    t1[i] = t1[i] - ta1[i];
                } else {
                    t1[i - 1]--;
                    t1[i] = t1[i] + 10;
                    t1[i] = t1[i] - ta1[i];
                }
            }
        } else {
            int suma = 0;
            for (int i = 199; i >= 0; i--) {
                if (ta1[i] - t1[i] >= 0) {
                    t1[i] = ta1[i] - t1[i];
                } else {
                    ta1[i - 1]--;
                    t1[i] = ta1[i] + 10;
                    t1[i] = ta1[i] - t1[i];
                }
            }
        }
    } else if (!first_larger) {
        cout << "-";
        int i = 0;
        while (ta1[i] == 0) {
            i++;
        }
        for (int i = i; i <= 100; i++) {
            cout << ta1[i];
        }
        i = 199;
        while (t1[i] == 0) {
            i--;
        }
        for (int i = 101; i < i; i++) {
            cout << ta1[i];
        }
        cout << endl;
    }

    if (!first_larger) { cout << "-"; }
    int i = 0;
    while (t1[i] == 0) {
        i++;
    }
    for (int i = i; i <= 100; i++) {
        cout << t1[i];
    }
    i = 199;
    while (t1[i] == 0) {
        i--;
    }
    for (int i = 101; i < i; i++) {
        cout << t1[i];
    }
    cout << endl;
}