#include <iostream>
#include <map>
#include <string>
#include <cctype>
using namespace std;

int main(int argc, char *argv[]) {
    int numCase;
    cin >> numCase;
    while (numCase--) {
        int N;
        cin >> N;
        string s;
        map<string, int> m;
        for (int i = 0; i < N; i++) {
            cin >> s;
            for (int j = 0; j < s.size(); j++) {
                s[j] = tolower(s[j]);
            }
            ++m[s];
        }
        map<string, int>::iterator it1 = m.begin(), it2 = m.end();
        while (it1 != it2) {
            cout << it1->first << ' ' << it1->second << endl;
            ++it1;
        }
        cout << endl;
    }
    return 0;
}
