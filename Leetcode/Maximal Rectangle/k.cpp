class Solution {
public:
    int maximalRectangle(vector<vector<char> >& matrix) {
        int maxArea = 0;
        int row = matrix.size();
        for (int i = 0; i < row; i++) {
            vector<int> histogram = calHistogram(matrix, i);
            int area = largestRectangleArea(histogram);
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }
    vector<int> calHistogram(vector<vector<char> >& matrix, int row) {
        int col = matrix[0].size();
        vector<int> height(col);
        for (int i = 0; i < col; i++) {
            int h = 0;
            int _row = row;
            while (_row >= 0 && matrix[_row][i] == '1') {
                --_row;
                ++h;
            }
            height[i] = h;
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