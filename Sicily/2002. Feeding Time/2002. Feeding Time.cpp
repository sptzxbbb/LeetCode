#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct node {
    int x, y;
    node(int _x, int _y) : x(_x), y(_y) {}
};

void bfs(vector<vector<char> >& map, int x, int y, int& count) {
    node start(x, y);
    queue<node> q;
    q.push(start);
    while (!q.empty()) {
        node cur = q.front();
        q.pop();
        if (map[cur.y][cur.x] == '.') {
            ++count;
            map[cur.y][cur.x] = '*';
            int dir[3] = {0, -1, 1};
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (i == 0 && j == 0) {
                        continue;
                    }
                    int _x = cur.x + dir[i], _y = cur.y + dir[j];
                    if (_x >= 0 && _x < (int)map[0].size() &&
                        _y >= 0 && _y < (int)map.size()
                        && map[_y][_x] == '.') {
                        node temp(_x, _y);
                        q.push(temp);
                    }
                }
            }
        }
    }
    return;
}

int main(int argc, char *argv[]) {
    int W, H;
    cin >> W >> H;
    if (W < 0 || H < 0) {
        cout << 0 << endl;
        return 0;
    }
    vector<vector<char> > map(H, vector<char>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> map[i][j];
        }
    }
    int grass = 0, count;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (map[i][j] == '.') {
                count = 0;
                bfs(map, j, i, count);
                grass = max(grass, count);
            }
        }
    }
    cout << grass << endl;
    return 0;
}
