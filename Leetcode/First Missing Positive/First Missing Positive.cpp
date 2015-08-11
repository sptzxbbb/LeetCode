class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();
        int pos = 0;
        while (pos < size) {
            if (nums[pos] != pos + 1 &&  nums[pos] != nums[nums[pos] - 1] && nums[pos] > 0 && nums[pos] <= size) {
                swap(nums[pos], nums[nums[pos] - 1]);
            } else {
                ++pos;
            }
        }
        for (int i = 0; i < size; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return size + 1;
    }
};