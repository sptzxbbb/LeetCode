// O(n^4) Solution
class Solution {
public:
    int maximalRectangle(vector<vector<char> >& matrix) {
        int row = matrix.size();
        if (row == 0) {
            return 0;
        }
        int col = matrix[0].size();
        int area = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                area = max(area, maxRectangle(matrix, i, j));
            }
        }
        return area;
    }
    int maxRectangle(vector<vector<char> >& matrix, int row, int col) {
        int maxArea = 0;
        int minWidth = INT_MAX;
        for (int i = row; i < matrix.size() && matrix[i][col] == '1'; i++) {
            int width = 0;
            while (col + width < matrix[row].size() && matrix[i][col + width] == '1') {
                ++width;
            }
            minWidth = min(minWidth, width);
            int curArea = minWidth * (i - row + 1);
            maxArea = max(maxArea, curArea);
        }
        return maxArea;
    }
};

"11111111"
"11111110"
"11111110"
"11111000"
"01111000"