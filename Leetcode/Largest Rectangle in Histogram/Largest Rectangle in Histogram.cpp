// O(n^2)
class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        int size = height.size();
        vector<int> area(size);
        int maxArea = 0;
        for (int i = 0; i < size; i++) {
            if (i + 1 < size && height[i] <= height[i + 1]) {
                continue;
            }
            int minHeight = height[i];
            for (int j = i; j >= 0; --j) {
                minHeight = min(minHeight, height[j]);
                int curArea = minHeight * (i - j + 1);
                maxArea = max(maxArea, curArea);
            }
        }
        return maxArea;
    }
};

// O(n)
class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        stack<int> s;
        h.push_back(0);
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