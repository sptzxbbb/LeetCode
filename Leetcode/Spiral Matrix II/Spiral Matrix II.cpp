class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > grid;
        // initialization
        vector<int> row(n, 0);
        for (int i = 0; i < n; i++) {
            grid.push_back(row);
        }
        int x[4] = {1, 0, -1, 0};
        int y[4] = {0, 1, 0, -1};
        int direction = 0;
        int curX = 0, curY = 0;
        int visitedRow = 0, visitedCol = 0;
        int length = 0, moveStep = 0, count = 1;
        while (true) {
            if (0 == x[direction]) {
                length = n - visitedRow;
            } else {
                length = n - visitedCol;
            }
            if (0 == length) {
                break;
            }
            grid[curY][curX] = count++;
            ++moveStep;
            // change direction
            if (length == moveStep) {
                visitedRow += (x[direction] == 0 ? 0 : 1);
                visitedCol += (y[direction] == 0 ? 0 : 1);
                direction = (direction + 1) % 4;
                moveStep = 0;
            }
            curX += x[direction];
            curY += y[direction];
        }
        return grid;
    }
};