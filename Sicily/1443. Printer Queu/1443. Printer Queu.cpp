#include <iostream>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

struct node {
    int value;
    bool my_job;
    node(int v, bool b) : value(v), my_job(b) {}
};

int main(int argc, char *argv[]) {
    int k;
    cin >> k;
    while (k--) {
        int n, m;
        cin >> n >> m;
        if (n == 0) {
            cout << 0 << endl;
            continue;
        }
        map<int, int, greater<int> > t;
        queue<node> q;
        int a, p;
        for (int i = 0; i < n; i++) {
            cin >> a;
            node e(a, false);
            if (i == m) {
                e.my_job = true;
                p = a;
            }
            q.push(e);
            ++t[a];
        }
        int time = 0;
        //auto it = t.begin();
        map<int, int, greater<int> >::iterator it = t.begin();
        while (!(q.front().my_job && it->first == p)) {
            if (q.front().value != it->first) {
                q.push(q.front());
                q.pop();
            } else {
                ++time;
                q.pop();
                --it->second;
                if (it->second == 0) {
                    t.erase(it);
                }
            }
            it = t.begin();
        }
        ++time;
        cout << time << endl;
    }
    return 0;
}

