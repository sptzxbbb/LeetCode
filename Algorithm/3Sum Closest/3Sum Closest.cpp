class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        if (size < 3) {
            return 0;
        }
        int sum = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < size; i++) {
            while (i > 0 && nums[i] == nums[i - 1]) ++i;
            twoSum(i, target, sum, size, nums);
        }
        return sum;
    }
    void twoSum(int k, int target, int& closetSum, int size, vector<int>& nums) {
        int i = k + 1, j = size - 1;
        int curSum;
        while (i < j) {
            curSum = nums[k] + nums[i] + nums[j];
            if (curSum == target) {
                closetSum = curSum;
                return;
            } else if (abs(target - curSum) < abs(target - closetSum)) {
                closetSum = curSum;
            }
            if (curSum > target) {
                --j;
                while (i < j && nums[j] == nums[j + 1]) --j;
            } else {
                while (i < j && nums[i] == nums[i - 1]) ++i;
                ++i;
            }

        }
        return;
    }
};