#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;
const int MAX = 105;

vector<int> child[MAX];
bool visit[MAX], inDegree[MAX], isForest;
int maxWidth, maxDepth;
int n, m;

void bfs() {
    int width = 0, depth = 0;
    vector<int> cur, next;
    for (int i = 1; i <= n; i++) {
        if (!inDegree[i]) {
            cur.push_back(i);
        }
    }
    while (!cur.empty()) {
        width = cur.size();
        for (int i = 0; i < (int)cur.size(); i++) {
            int index = cur[i];
            visit[index] = true;
            for (int j = 0; j < (int)child[index].size(); j++) {
                next.push_back(child[index][j]);
            }
        }
        swap(cur, next);
        next.clear();
        if (!cur.empty()) {
            ++depth;
        }
        maxWidth = max(width, maxWidth);
        maxDepth = max(depth, maxDepth);
    }
}

int main(int argc, char *argv[]) {
    while (cin >> n >> m, n != 0) {
        // initial
        memset(child, 0, sizeof(child));
        memset(visit, false, sizeof(visit));
        memset(inDegree, false, sizeof(inDegree));
        isForest = true;
        maxWidth = 0;
        maxDepth = 0;
        // input
        int a, b;
        for (int i = 0; i < m; ++i) {
            cin >> a >> b;
            child[a].push_back(b);
            if (a == b || inDegree[b]) {
                isForest = false;
            } else {
                inDegree[b] = true;
            }
        }
        // test if two or more edges point to same node;
        if (!isForest) {
            cout << "INVALID" << endl;
            continue;
        }
        bfs();
        // test loop
        for (int i = 1; i <= n; i++) {
            if (!visit[i]) {
                isForest = false;
                break;
            }
        }
        if (!isForest) {
            cout << "INVALID" << endl;
        } else {
            cout << maxDepth << ' ' << maxWidth << endl;
        }
    }
    return 0;
}
