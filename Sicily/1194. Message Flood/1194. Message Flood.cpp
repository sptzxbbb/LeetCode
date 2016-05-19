#include <iostream>
#include <string>
#include <set>
using namespace std;

class Solution {
  public:
    int left(set<string>& send, set<string>& receive) {
        for (set<string>::iterator it = receive.begin(); it != receive.end(); ++it) {
            string x = (*it);
            if (send.find(x) != send.end()) {
                send.erase(x);
            }
        }
        return send.size();
    }
};

void lower(string& s) {
    for (int i = 0; i < (int)s.size(); ++i) {
        if (isupper(s[i])) {
            s[i] = tolower(s[i]);
        }
    }
    return;
}

int main(int argc, char *argv[]) {
    int n, m;
    while (cin >> n && n != 0) {
        cin >> m;
        set<string> send, receive;
        string s;
        for (int i = 0; i < n; ++i) {
            cin >> s;
            lower(s);
            send.insert(s);
        }
        for (int i = 0; i < m; ++i) {
            cin >> s;
            lower(s);
            receive.insert(s);
        }
        Solution k;
        cout << k.left(send, receive) << endl;
    }

    return 0;
}













