#include <iostream>

using namespace std;

int b, n, m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    int a[n], k = n;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 1; i < n; i++)
        a[i] = min(a[i - 1], a[i]);

    for (int i = 0; i < m; i++) {
        cin >> b;
        while (k > 0 && a[--k] < b);
        if (a[k] < b) {
            cout << "0\n";
            return 0;
        }
        a[k] = -1;
    }
    cout << k + 1 << endl;
}