#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[]) {
    int m;
    cin >> m;
    vector<string> s(m);
    for (int i = 0; i < m; i++) {
        cin >> s[i];
        int pos = s[i].find_first_of('_');
        if (pos == (int)string::npos) {
            pos = -1;
        }
        // reverse first part
        int start = 0, end = pos - 1;
        if (start <= end) {
            for (int j = start; j <= (start + end) / 2; j++) {
                swap(s[i][j], s[i][start + end - j]);
            }
        }
        // reverse second part
        start = pos + 1, end = s[i].size() - 1;
        if (start <= end) {
            for (int j = start; j <= (start + end) / 2; j++) {
                swap(s[i][j], s[i][start + end - j]);
            }
        }
    }
    for (int i = 0; i < m; i++) {
        cout << s[i] << endl;
    }
    return 0;
}
