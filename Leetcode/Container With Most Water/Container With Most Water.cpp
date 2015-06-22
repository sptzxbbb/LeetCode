class Solution {
public:
    int maxArea(vector<int>& height) {
        int volume = 0;
        int i = 0, j = height.size() - 1;
        while (i < j) {
            volume = max(volume, (j - i) * min(height[i], height[j]));
            height[i] < height[j] ? ++i : --j;
        }
        return volume;
    }
};


















