#include <iostream>

using namespace std;

int T[200000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int end = 0;
    int beg = 0;
    for (int i = 0; i < n; ++i) {
        char action;
        cin >> action;

        switch (action) {
            case '+':
                cin >> T[end];
                end++;
                break;
            case '-':
                cout << T[beg] << "\n";
                beg++;
                break;
            default:
                break;
        }
    }
    return 0;
}