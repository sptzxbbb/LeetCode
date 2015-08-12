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
                    bfs(grid, i, j);
                    ++num;
                }
            }
        }
        return num;
    }
    void bfs(vector<vector<char> >& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
            return;
        }
        if (grid[i][j] != '1') {
            return;
        }
        grid[i][j] = -1;
        bfs(grid, i - 1, j);
        bfs(grid, i + 1, j);
        bfs(grid, i, j - 1);
        bfs(grid, i, j + 1);
    }
};


int main(int argc, char *argv[])
{
    vector<vector<char> > grid(1, vector<char>(3, '1'));
    grid[0][1] = '0';
    Solution k;
    cout << k.numIslands(grid) << endl;
    return 0;
}
