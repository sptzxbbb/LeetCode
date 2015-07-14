class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        int pos = binarySearch(nums, left, right, target);
        return pos;
    }
    // search the first element greater than or equal to target
    int binarySearch(vector<int>& nums, int left, int right, int target) {
        if (left >= right) {
            return left;
        }

        int mid = (left + right) / 2;

        if (nums[mid] >= target &&
            ((left < mid && nums[mid - 1] < target) ||
                0 == mid)) {
            return mid;
        }

        if (nums[mid] < target) {
            return binarySearch(nums, mid + 1, right, target);
        }
        if (nums[mid] >= target) {
            return binarySearch(nums, left, mid, target);
        }
    }
};

