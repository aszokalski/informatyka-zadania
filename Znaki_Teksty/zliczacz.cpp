#include <iostream>
#include <string>
#include <limits>
#include <algorithm>

using namespace std;

int main() {
    string s = "";
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int x = 0; x < n; ++x) {
        string line;
        getline(cin, line);
        s += line + ' ';
    }

    for (int i = 97; i <= 122; ++i) {
        char litera = char(i);
        int wystapienia = std::count(s.begin(), s.end(), litera);
        if (wystapienia != 0)
            cout << litera << " " << wystapienia << endl;

    }
    for (int i = 65; i <= 90; ++i) {
        char litera = char(i);
        int wystapienia = std::count(s.begin(), s.end(), litera);
        if (wystapienia != 0)
            cout << litera << " " << wystapienia << endl;
    }
    return 0;
}