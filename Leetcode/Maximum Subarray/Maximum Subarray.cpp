class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        if (0 == size) {
            return 0;
        }
        int local = nums[0], global = nums[0];
        for (int i = 1; i < size; i++) {
            local = max(nums[i], local + nums[i]);
            global = max(local, global);
        }
        return global;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return maxSubArraySum(nums, 0, nums.size() - 1);
    }

    int maxSubArraySum(vector<int>& nums, int left, int right) {
        if (left == right) {
            return nums[left];
        }
        int mid = (left + right) / 2;

        return max(max(maxSubArraySum(nums, left, mid),
                       maxSubArraySum(nums, mid + 1, right)),
                   maxCrossingSum(nums, left, mid, right));
    }

    int maxCrossingSum(vector<int>& nums, int left, int mid, int right) {
        int sum = 0;
        int left_sum = INT_MIN;
        for (int i = mid; i >= l; --i) {
            sum += nums[i];
            left_sum = max(left_sum, sum);
        }
        sum = 0;
        int right_sum = INT_MIN;
        for (int i = mid + 1; i <= right; i++) {
            sum += nums[i];
            right_sum = max(right_sum, sum);
        }
        return left_sum + right_sum;
    }
};

