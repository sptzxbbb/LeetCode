#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(int argc, char *argv[]) {
    int numberOfCase;
    cin >> numberOfCase;
    while (numberOfCase--) {
        int n, m;
        cin >> n >> m;
        vector<int> inDegree(n + 1, 0);
        vector<int> outDegree[n + 1];
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            inDegree[b]++;
            outDegree[a].push_back(b);
        }
        priority_queue<int, vector<int>, greater<int> > q;
        for (int i = 1; i <= n; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int cur = q.top();
            q.pop();
            cout << cur << ' ';
            for (int i = 0; i < (int)outDegree[cur].size(); i++) {
                int index = outDegree[cur][i];
                --inDegree[index];
                if (inDegree[index] == 0) {
                    q.push(index);
                }
            }
        }
        cout << endl;
    }
    return 0;
}
