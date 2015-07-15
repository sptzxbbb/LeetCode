class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        int Min[row][col];

        Min[0][0] = grid[0][0];

        for (int i = 1; i < col; i++) {
            Min[0][i] = Min[0][i - 1] + grid[0][i];
        }

        for (int i = 1; i < row; i++) {
            Min[i][0] = Min[i - 1][0] + grid[i][0];
        }

        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                Min[i][j] = min(Min[i - 1][j], Min[i][j - 1]) + grid[i][j];
            }
        }
        return Min[row - 1][col - 1];
    }
};

