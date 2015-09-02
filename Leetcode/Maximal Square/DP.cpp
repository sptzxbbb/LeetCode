class Solution {
public:
    int maximalSquare(vector<vector<char> >& matrix) {
        int row = matrix.size();
        if (row == 0) {
            return 0;
        }
        int col = matrix[0].size();
        int area[row][col] = {0};
        int maxSize = 0;
        // the first row
        for (int i = 0; i < col; i++) {
            area[0][i] = matrix[0][i] - '0';
            if (area[0][i] == 1) {
                maxSize = 1;
            }
        }
        // the first col
        for (int i = 0; i < row; i++) {
            area[i][0] = matrix[i][0] - '0';
            if (area[i][0] == 1) {
                maxSize = 1;
            }
        }3
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (matrix[i][j] == '1') {
                    area[i][j] = min(area[i - 1][j - 1], min(area[i][j - 1], area[i - 1][j])) + 1;
                    maxSize = max(maxSize, area[i][j]);
                }
            }
        }
        return maxSize * maxSize;
    }
};