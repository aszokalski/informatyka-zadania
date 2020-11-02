#include <iostream>

using namespace std;

struct make {
    bool _occure = false;
    int _count = 0;
};

make product[100];

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin >> n;

    int quantity;
    char type;
    for (int i = 0; i < n; i++) {
        cin >> type >> quantity;

        product[type]._occure = true;
        product[type]._count += quantity;
    }

    for (int i = 0; i < 100; i++)
        if (product[i]._occure) cout << char(i) << " " << product[i]._count << endl;
}
