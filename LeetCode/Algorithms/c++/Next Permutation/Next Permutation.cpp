class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        int index1 = -1, index2;
        for (int i = size - 1; i >= 1; --i) {
            if (nums[i] > nums[i - 1]) {
                index1 = i - 1;
                break;
            }
        }
        if (-1 == index1) {
            sort(nums.begin(), nums.end());
            return;
        } else {
            for (int i = size - 1; i > index1; --i) {
                if (nums[i] > nums[index1]) {
                    index2 = i;
                    break;
                }
            }
            swap(nums[index1], nums[index2]);
            for (int i = index1 + 1; i < (size + (index1 + 1)) / 2; i++) {
                swap(nums[i], nums[size + index1 - i]);
            }
            return;
        }
    }
};
