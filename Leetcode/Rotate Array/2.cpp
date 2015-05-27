#include <queue>
class Solution {
public:
    void rotate(int nums[], int n, int k) {
        queue<int> trans;
        k %= n;
	for (int i = 0; i < k; ++i) {
	    trans.push(nums[n - k + i]);
	    cout << nums[n - k + i] << ' ';
	}
	for (int i = n - k - 1; i >= 0; --i) {
	    nums[i + k] = nums[i];
	}

	for (int i = 0; i < k; ++i) {
	    nums[i] = trans.front();
	    trans.pop();
	}
    }
};
