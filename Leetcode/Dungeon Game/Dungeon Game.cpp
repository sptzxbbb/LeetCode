#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int> >& dungeon) {
        // abnormal case
        if (dungeon.size() == 0 || dungeon[0].size() == 0) {
            return 0;
        }
        int row = dungeon.size();
        int col = dungeon[0].size();
        vector<vector<int> > HP(row, vector<int>(col));
        if (dungeon[row - 1][col - 1] >= 0) {
            HP[row - 1][col - 1] = 1;
        } else {
            HP[row - 1][col - 1] = 1 - dungeon[row - 1][col - 1];
        }
        for (int i = row - 2; i >= 0; i--) {
            HP[i][col - 1] = max(HP[i + 1][col - 1] - dungeon[i][col - 1], 1);
        }
        for (int i = col - 2; i >= 0; i--) {
            HP[row - 1][i] = max(HP[row - 1][i + 1] - dungeon[row - 1][i], 1);
        }
        for (int i = row - 2; i >= 0; i--) {
            for (int j = col - 2; j >= 0; j--) {
                HP[i][j] = max(min(HP[i + 1][j], HP[i][j + 1]) - dungeon[i][j], 1);
            }
        }
        return HP[0][0];
    }
};

int main(int argc, char *argv[])
{
    vector<vector<int> > maze;

    vector<int> a;
    a.push_back(1);
    a.push_back(-2);
    a.push_back(-3);

    vector<int> b;
    b.push_back(2);
    b.push_back(-2);
    b.push_back(-2);
    maze.push_back(a);
    maze.push_back(b);

    Solution k;
    cout << k.calculateMinimumHP(maze) << endl;

    return 0;
}
