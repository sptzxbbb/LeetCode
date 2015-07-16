class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int size = nums.size();
        int start = 0, end = size - 1, mid;
        while (start <= end) {
            mid = (start + end) / 2;
            if ((mid == size - 1 || nums[mid] > nums[mid + 1]) &&
                (mid == 0 || nums[mid] > nums[mid - 1])) {
                return mid;
            } else if (mid > 0 && nums[mid] < nums[mid - 1]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return mid;
    }
};

