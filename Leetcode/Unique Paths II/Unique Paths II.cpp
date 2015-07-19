class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
        int row  = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        int grid[row][col];
        bool firstRow = true, firstCol = true;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (0 == i && 0 == j) {
                    if (1 == obstacleGrid[i][j]) {
                        firstRow = false;
                        firstCol = false;
                        grid[i][j] = 0;
                    } else {
                        grid[i][j] = 1;
                    }
                } else if (0 == i) {
                    if (1 == obstacleGrid[i][j]) {
                        firstRow = false;
                    }
                    if (firstRow) {
                        grid[i][j] = 1;
                    } else {
                        grid[i][j] = 0;
                    }
                } else if (0 == j) {
                    if (1 == obstacleGrid[i][j]) {
                        firstCol = false;
                    }
                    if (firstCol) {
                        grid[i][j] = 1;
                    } else {
                        grid[i][j] = 0;
                    }
                } else {
                    if (1 == obstacleGrid[i][j]) {
                        grid[i][j] = 0;
                    } else {
                        grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
                    }
                }
            }
        }
        return grid[row - 1][col - 1];
    }
};

