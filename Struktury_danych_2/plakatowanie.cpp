#include <iostream>
#include <stack>

using namespace std;

int INF = 1000000005;
int T[250005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int x;
    for (int i = 1; i <= n; i++)
        cin >> x >> T[i];

    int res = 0;
    stack<int> s;
    s.push(0);
    for (int i = 1; i <= n; i++) {
        while (s.top() > T[i]) {
            s.pop();
        }
        if (s.top() < T[i]) {
            s.push(T[i]), res++;
        }
    }
    cout << res << '\n';
    return 0;
}