#include <iostream>
#include <vector>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T[200000];
    vector<int> rev;

    int n;
    cin >> n;

    int index = 0;
    for (int i = 0; i < n; ++i) {
        char action;
        cin >> action;

        switch (action) {
            case '+': {
                index++;
                cin >> T[index];
                rev.push_back(-1);
                break;
            }
            case '-': {
                rev.push_back(T[index]);
                index--;
                break;
            }
            case '*': {

                int y;
                cin >> y;

                int s = rev.size();
                for (int j = s - 1; j >= s - y; --j) {

                    int elem = rev[j];

                    if (elem == -1) {
                        rev.push_back(T[index]);
                        index--;
                    } else {
                        index++;
                        T[index] = elem;
                        rev.push_back(-1);
                    }
                }
                break;
            }
            default:
                break;
        }
        if (index == 0) {
            cout << -1 << '\n';
        } else {
            cout << T[index] << '\n';
        }
    }
    return 0;
}