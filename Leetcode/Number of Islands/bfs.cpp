#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct node {
    int x;
    int y;
    node(int row = 0, int col = 0) : x(row), y(col) {};
};

class Solution {
  public:
    int numIslands(vector<vector<char> >& grid) {
        int row = grid.size();
        if (row == 0) {
            return 0;
        }
        int col = grid[0].size();
        int num = 0;
        vector<vector<bool> > visit(row, vector<bool>(col, false));
        // scan the grid map
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (false == visit[i][j] && '1' == grid[i][j]) {
                    // using bfs to visit this island
                    queue<node> q;
                    node s(i, j);
                    q.push(s);
                    visit[i][j] = true;
                    int x[4] = {0, 1, -1, 0};
                    int y[4] = {1, 0, 0, -1};
                    while (q.size()) {
                        node cur = q.front();
                        q.pop();
                        // 4 directions
                        for (int k = 0; k < 4; k++) {
                            node next(cur.x + x[k], cur.y + y[k]);
                            if (next.x >= 0 && next.x < row &&
                                next.y >= 0 && next.y < col &&
                                grid[next.x][next.y] == '1' &&
                                visit[next.x][next.y] == false) {
                                q.push(next);
                                visit[next.x][next.y] = true;
                            }
                        }
                    }
                    ++num;
                }
            }
        }
        return num;
    }
};

int main(int argc, char *argv[])
{
    vector<vector<char> > grid(1, vector<char>(3, '0'));
    grid[0][0] = '1';
    grid[2][2] = '1';
    Solution k;
    cout << k.numIslands(grid) << endl;
    return 0;
}
