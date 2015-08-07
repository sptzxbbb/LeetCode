class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        int size = nums.size();
        vector<vector<int> > res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < size - 3; i++) {
            while (i > 0 && nums[i] == nums[i - 1]) ++i;

            for (int j = i + 1; j < size - 2; j++) {
                while (j > i + 1 && nums[j] == nums[j - 1]) ++j;

                int twoSum = target - nums[i] - nums[j];
                int head = j + 1, tail = size - 1;
                while (head < tail) {
                    int sum = nums[head] + nums[tail];
                    if (sum > twoSum) {
                        --tail;
                    } else if (sum < twoSum) {
                        ++head;
                    } else {
                        res.push_back({nums[i], nums[j], nums[head], nums[tail]});
                        ++head;
                        while (head < tail && nums[head] == nums[head - 1]) ++head;
                        --tail;
                        while (head < tail && nums[tail] == nums[tail + 1]) --tail;
                    }
                }
            }
        }
        return res;
    }
};