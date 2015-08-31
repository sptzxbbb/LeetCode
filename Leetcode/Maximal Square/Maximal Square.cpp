class Solution {
  public:
    int maximalSquare(vector<vector<char> >& matrix) {
        int maxArea = 0;
        if (matrix.size() == 0) {
            return 0;
        }
        int row = matrix.size();
        vector<vector<int> > histogram = calHistogram(matrix);
        for (int i = 0; i < row; i++) {
            int area = largestArea(histogram[i]);
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }
    vector<vector<int> > calHistogram(vector<vector<char> >& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int> > height(row, vector<int>(col, 0));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (i == 0) {
                    if (matrix[i][j] == '1') {
                        height[i][j] = 1;
                    }
                } else {
                    if (matrix[i][j] == '1') {
                        if (height[i - 1][j] != 0) {
                            height[i][j] = height[i - 1][j] + 1;
                        } else {
                            height[i][j] = 1;
                        }
                    }
                }
            }
        }
        return height;
    }
    int largestArea(vector<int>& height) {
        int maxArea = 0;
        for (int i = 0; i < height.size(); i++) {
            bool exist = true;
            // left square
            if (i - height[i] - 1 >= 0) {
                for (int j = i; j >= i - height[i] - 1; i--) {
                    if (height[j] < height[i]) {
                        exist = false;
                        break;
                    }
                }
                if (exist) {
                    int area = height[i] * height[i];
                    maxArea = max(area, maxArea);
                    continue;
                }
            }
            exist = true;
            // right square
            if (i + height[i] - 1 < height.size()) {
                for (int j = i; j <= i + height[i] - 1; j++) {
                    if (height[j] < height[i]) {
                        exist = false;
                        break;
                    }
                }
                if (exist) {
                    int area = height[i] * height[i];
                    maxArea = max(area, maxArea);
                }
            }
        }
        return maxArea;
    }
}