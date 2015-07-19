class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;
        int ans = nums[0];
        while (start <= end) {
            if (start == end) {
                ans = min(ans, nums[start]);
                break;
            }
            int mid = (start + end) / 2;
            if (nums[start] < nums[mid]) {
                ans = min(ans, nums[start]);
                start = mid + 1;
            } else if (nums[start] > nums[mid]) {
                ans = min(ans, nums[mid]);
                end = mid - 1;
            } else {
                ans = min(ans, nums[start]);
                ++start;
            }
        }
        return ans;
    }
};