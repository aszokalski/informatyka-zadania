#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string s;
    cin >> s;

    int max_len = 0;
    int len = 0;
    for (auto lit : s) {
        if (lit == 'a') {
            len++;
        } else {
            max_len = max(len, max_len);
            len = 0;
        }
    }

    max_len = max(len, max_len);

    if (max_len) {
        string ret(max_len, 'a');
        cout << ret << endl;
    } else {
        cout << "BRAK" << endl;
    }

    return 0;
}