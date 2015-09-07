class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        if (0 == size) {
            return 0;
        }

        int max = 0;
        for (int i = 0; i < size; i++) {
            if (height[i] > max) {
                max = height[i];
            }
        }
        int water = 0;
        int left = 0, shortest = height[0];
        while (height[left] != max) {
            if (height[left] < shortest) {
                water += shortest - height[left];
            } else {
                shortest = height[left];
            }
            ++left;
        }
        int right = size - 1;
        shortest = height[right];
        while (height[right] != max) {
            if (height[right] < shortest) {
                water += shortest - height[right];
            } else {
                shortest = height[right];
            }
            --right;
        }
        // the volume of water between two highest board, if possible
        while (left != right) {
            water += max - height[left];
            ++left;
        }
        return water;
    }
};