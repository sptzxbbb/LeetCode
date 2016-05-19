#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main(int argc, char *argv[]) {
    int n, m, L, x, y;
    cin >> n >> m >> L;
    int road[n + 1][n + 1][L + 1];
    memset(road, 0, sizeof(road));
    vector<int> next[n + 1];
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        road[x][y][1] = 1;
        next[x].push_back(y);
    }
    for (int l = 2; l <= L; l++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = 0; k < (int)next[i].size(); k++) {
                    road[i][j][l] += road[next[i][k]][j][l - 1];
                }
            }
        }
    }
    int q, A, B;
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> A >> B;
        cout << road[A][B][L] << endl;
    }
    return 0;
}
