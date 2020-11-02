#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    vector<bool> is_prime(pow(10, 6) + 1, true);
    vector<long long int> ilosci = {0, 0};
    for (long long int i = 2; i <= pow(10, 6); ++i) {
        if (is_prime[i]) {
            ilosci.push_back(ilosci[i - 1] + 1);
            for (long long int j = i * 2; j <= pow(10, 6); j += i) {
                is_prime[j] = false;
            }
        } else {
            ilosci.push_back(ilosci[i - 1]);
        }
    }

    int n;
    cin >> n;

    vector<pair<int, int>> args;

    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        args.emplace_back(make_pair(a, b));
    }

    for (auto a : args) {
        cout << ilosci[a.second] - ilosci[a.first - 1] << endl;
    }

    return 0;
}
