//
// Created by Adam Szokalski on 14/11/2019.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;
    int curr_max = 1;
    char curr_max_chr = s[0];

    int curr = 1;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == s[i - 1]) {
            curr++;
        }
        if (s[i] != s[i - 1] || i == s.size() - 1) {
            if (curr == curr_max) {
                curr_max_chr = max(curr_max_chr, s[i - 1]);
                curr = 1;
            } else if (curr > curr_max) {
                curr_max = curr;
                curr_max_chr = s[i - 1];
                curr = 1;
            }
        }
    }

    for (int j = 0; j < curr_max; ++j) {
        cout << curr_max_chr;
    }
    cout << endl;


    return 0;
}
