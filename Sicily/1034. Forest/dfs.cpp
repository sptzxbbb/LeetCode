#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;
const int MAX = 105;

vector<int> child[MAX];
int widths[MAX];
bool visit[MAX], inDegree[MAX], isForest;
int maxWidth, maxDepth;

void dfs(int index, int depth) {
    visit[index] = true;
    ++widths[depth];
    maxDepth = max(depth, maxDepth);
    maxWidth = max(widths[depth], maxWidth);
    for (int i = 0; i < (int)child[index].size(); i++) {
        dfs(child[index][i], depth + 1);
    }
}

int main(int argc, char *argv[]) {
    int n, m;
    while (cin >> n >> m, n != 0) {
        // initial
        memset(child, 0, sizeof(child));
        memset(widths, 0, sizeof(widths));
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

        for (int i = 1; i <= n; i++) {
            if (!inDegree[i]) {
                dfs(i, 0);
            }
        }
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
