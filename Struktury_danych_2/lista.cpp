#include <iostream>
#include <list>
#include <iterator>

using namespace std;

int main() {
    list<int> T;
    list<int>::iterator O[200000];
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        char action;
        cin >> action;
        int x, y;
        switch (action) {
            case '>': {
                cin >> x;
                T.push_front(x);
                O[i] = T.begin();
                break;
            }
            case '<': {
                T.pop_front();
                break;
            }
            case '+': {
                cin >> x >> y;
                auto it = O[y - 1];
                T.insert(next(it), x);
                O[i] = next(it);
                break;
            }
            case '-': {
                cin >> y;
                auto it = O[y - 1];
                T.erase(it);
                break;
            }
            default:
                break;
        }
    }

    for (int n : T) {
        cout << n << " ";
    }
    cout << "\n";
    return 0;
}