class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> ans;
        int row = matrix.size();
        if (0 == row) {
            return ans;
        }
        int col = matrix[0].size();
        if (0 == col) {
            return ans;
        }

        int x[4] = {1, 0, -1, 0};
        int y[4] = {0, 1, 0, -1};
        int direction = 0;
        int curX = 0, curY = 0;
        int visitedRow = 0, visitedCol = 0;
        int length = 0, moveStep = 0;
        while (true) {
            if (0 == x[direction]) {
                length = row - visitedRow;
            } else {
                length = col - visitedCol;
            }
            if (0 == length) {
                break;
            }
            ans.push_back(matrix[curY][curX]);
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
        return ans;
    }
};