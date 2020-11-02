#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);

    string word1;
    string word2;
    cin >> word1 >> word2;

    int n = word1.size();
    int m = word2.size();

    int x, y;
    int score = 0;
    int current = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            current = 0;
            x = i;
            y = j;

            while (x < n && y < m) {
                if (word1[x] != word2[y]) break;

                current++;
                x++;
                y++;
            }

            score = max(score, current);
        }
    }

    cout << score;

    return 0;
}
