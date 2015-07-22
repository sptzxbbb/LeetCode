class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        int value[size];
        int _max = -1;

        if (0 == size) {
            return 0;
        } else if (1 == size) {
            return nums[0];
        } else if (2 == size) {
            return max(nums[0], nums[1]);
        }

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < size; j++) {
                if (0 == j) {
                    if (0 == i) {
                        value[j] = nums[j];
                    } else {
                        value[j] = 0;
                    }
                } else if (1 == j) {
                    value[j] = max(value[j - 1], nums[j]);
                } else {
                    value[j] = max(value[j - 1], value[j - 2] + nums[j]);
                }
            }
            if (0 == i) {
                _max = value[size - 2];
            } else {
                _max = max(_max, value[size - 1]);
            }
        }
        return _max;
    }
};