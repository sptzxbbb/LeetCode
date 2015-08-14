// O(n^2) Solution
class Solution {
public:
    int maximalRectangle(vector<vector<char> >& matrix) {
        int maxArea = 0;
        int row = matrix.size();
        if (0 == row) {
            return maxArea;
        }
        vector<vector<int> > histogram = calHistogram(matrix);
        for (int i = 0; i < row; i++) {
            int area = largestRectangleArea(histogram[i]);
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
    int largestRectangleArea(vector<int>& height) {
        stack<int> s;
        height.push_back(0);
        int sum = 0, size = height.size();
        for (int i = 0; i < size; i++) {
            if (s.empty() || height[i] > height[s.top()]) {
                s.push(i);
            } else {
                int t = s.top();
                s.pop();
                int area = height[t] * (s.empty() ? i : i - s.top() - 1);
                sum = max(sum, area);
                --i;
            }
        }
        return sum;
    }
};