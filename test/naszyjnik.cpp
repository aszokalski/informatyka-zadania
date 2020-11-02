#include <iostream>

using namespace std;

bool occur(char letter, string word) {
    int n = word.size();
    for (int i = 0; i < n; i++)
        if (letter == word[i]) return true;

    return false;
}

char change(char letter) {
    if (letter >= 97) {
        if (occur(letter, "aeiouy")) return '2';
        else return '1';
    }

    if (occur(letter, "AEIOUY")) return '4';
    else return '3';
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin >> n;

    string word;
    for (int i = 0; i < n; i++) {

        cin >> word;
        int length = word.size();

        for (int j = 0; j < length; j++)
            word[j] = change(word[j]);

        word += word[0];
        int spot = 1;
        while (word[spot] == word[spot - 1] && spot < length) {
            word += word[spot];
            spot++;
        }


        int max_len = 0;
        int min_len = 2000 * 1000;
        int max_type = 0;
        int min_type = 0;
        int current = 1;
        for (int i = spot + 1; i < spot + length; i++) {

            if (word[i] == word[i - 1]) current++;
            else {
                if (current == max_len) max_type = max(max_type, word[i - 1] - 48);
                if (current == min_len) min_type = max(min_type, word[i - 1] - 48);

                if (current > max_len) {
                    max_len = current;
                    max_type = word[i - 1] - 48;
                }

                if (current < min_len) {
                    min_len = current;
                    min_type = word[i - 1] - 48;
                }
                current = 1;
            }
        }
        if (current == max_len) max_type = max(max_type, word[length + spot - 1] - 48);
        if (current == min_len) min_type = max(min_type, word[length + spot - 1] - 48);

        if (current > max_len) {
            max_len = current;
            max_type = word[length + spot - 1] - 48;
        }

        if (current < min_len) {
            min_len = current;
            min_type = word[length + spot - 1] - 48;
        }


        string _max_type, _min_type;

        if (max_type == 1) _max_type = "ciemne";
        if (max_type == 2) _max_type = "jasne";
        if (max_type == 3) _max_type = "CIEMNE";
        if (max_type == 4) _max_type = "JASNE";

        if (min_type == 1) _min_type = "ciemne";
        if (min_type == 2) _min_type = "jasne";
        if (min_type == 3) _min_type = "CIEMNE";
        if (min_type == 4) _min_type = "JASNE";

        cout << max_len << " " << _max_type << endl;
        cout << min_len << " " << _min_type << endl;
    }
}
