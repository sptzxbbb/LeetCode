class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > res;
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            twoSum(res, nums, -nums[i], i);
        }
        return res;
    }
    void twoSum(vector<vector<int> >& res , vector<int>& nums, int target, int index_target) {
        int size = nums.size();
        int i = index_target + 1, j = size - 1;
        int sum;
        while (i < j) {
            sum = nums[i] + nums[j];
            if (sum < target) {
                ++i;
                while (i < j && nums[i] == nums[i - 1]) ++i;
            } else if (sum > target) {
                --j;
                while (i < j && nums[j] == nums[j + 1]) --j;
            } else if (sum == target) {
                vector<int> v;
                res.push_back({-target, nums[i], nums[j]});
                ++i;
                while (i < j && nums[i] == nums[i - 1]) ++i;
                --j;
                while (i < j && nums[j] == nums[j + 1]) --j;
            }
        }
        return;
    }
};