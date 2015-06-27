class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        int ans = binary_search(nums, low, high);
        return nums[ans];
    }

    int binary_search(vector<int>& nums, int low, int high) {
        // if the array is not rotated at all
        if (nums[low] < nums[high]) {
            return nums[0];
        }
        if (low == high) {
            return nums[low];
        }
        int mid = (low + high) / 2;
        if (mid < high && nums[mid] > nums[mid + 1]) {
            return nums[mid + 1];
        }
        if (mid > low && nums[mid - 1] > nums[mid]) {
            return nums[mid];
        }
        if (nums[mid] < nums[high]) {
            return binary_search(nums, low, mid - 1);
        } else {
            return binary_search(nums, mid + 1, high);
        }
    }
};



















