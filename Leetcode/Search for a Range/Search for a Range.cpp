class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = nums.size(), end = -1;
        binarySearch(nums, 0, nums.size() - 1, start, end, target);

        vector<int> ans;
        if (nums.size() == start) {
            start = -1;
        }
        ans.push_back(start);
        ans.push_back(end);
        return ans;
    }
    void binarySearch(vector<int>& nums, int left, int right, int& start, int& end, int target) {
        if (left > right) {
            return;
        }
        int mid = (left + right) / 2;
        if (nums[mid] < target) {
            binarySearch(nums, mid + 1, right, start, end, target);
        } else if (nums[mid] > target) {
            binarySearch(nums, left, mid - 1, start, end, target);
        } else {
            if (mid < start) {
                start = mid;
            }
            if (mid > end) {
                end = mid;
            }
            binarySearch(nums, mid + 1, right, start, end, target);
            binarySearch(nums, left, mid - 1, start, end, target);
        }
        return;
    }
};
