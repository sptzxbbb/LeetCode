class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        int occur = 1, pos = 1, length = 1;
        if (0 == nums.size()) {
            return 0;
        }
        for (int i = 1; i < size; i++) {
            if (nums[i - 1] == nums[i]) {
                if (1 == occur) {
                    nums[pos++] = nums[i];
                    ++occur;
                    ++length;
                }
            } else if (nums[i - 1] != nums[i]) {
                occur = 1;
                nums[pos++] = nums[i];
                ++length;
            }
        }
        return length;
    }
};