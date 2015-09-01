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
            int left = i - height[i] + 1;
            if (left < 0) {
                left = 0;
            }
            int right = i + height[i] - 1;
            if (right >= height.size()) {
                right = height.size() - 1;
            }
            int index = left;
            int width = 0;
            int area = 0;
            while (index <= right) {
                if (height[index] >= height[i]) {
                    ++width;
                } else {
                    width = 0;
                }
                ++index;
                if (width >= height[i]) {
                    area = height[i] * height[i];
                    break;
                }
            }
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }
};