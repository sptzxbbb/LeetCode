#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
    int n;
    cin >> n;
    while (n--) {
        string s, res;
        cin >> s;
        for (int i = 0; i < (int)s.size(); i++) {
            s[i] = toupper(s[i]);
            if (s[i] >= 'A' && s[i] <= 'C') {
                res += '2';
            } else if (s[i] >= 'D' && s[i] <= 'F') {
                res += '3';
            } else if (s[i] >= 'G' && s[i] <= 'I') {
                res += '4';
            } else if (s[i] >= 'J' && s[i] <= 'L') {
                res += '5';
            } else if (s[i] >= 'M' && s[i] <= 'O') {
                res += '6';
            } else if (s[i] >= 'P' && s[i] <= 'S') {
                res += '7';
            } else if (s[i] >= 'T' && s[i] <= 'V') {
                res += '8';
            } else if (s[i] >= 'W' && s[i] <= 'Z') {
                res += '9';
            }
        }
        bool palin = true;
        for (int i = 0; i <= ((int)res.size() / 2); i++) {
            if (res[i] != res[res.size() - 1 - i]) {
                palin = false;
                break;
            }
        }
        if (palin) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
