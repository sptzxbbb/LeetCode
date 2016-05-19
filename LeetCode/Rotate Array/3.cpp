class Solution {
public:
    void rotate(int nums[], int n, int k) {
	k %= n;
        if(0 == n || 0 == k) {
	    return;
	}
        reverse(nums, n - k, n - 1);
        reverse(nums, 0, n - k - 1);
        reverse(nums, 0, n - 1);
    }

    void reverse(int nums[], int i, int j) {
        for(; i < j; ++i, --j) {
	    swap(nums[i], nums[j]);
	}
    }
};
