#include <queue>
class Solution {
public:
    void rotate(int nums[], int n, int k) {
        queue<int> ans;
	for (int i = 0; i < n; ++i) {
	    ans.push(nums[n - 1 - i]);
	}
	for (int i = 0; i < k; ++i) {
	    ans.push(ans.front());
	    ans.pop();
	}
	for (int i = n - 1; i >= 0; --i) {
	    nums[i] = ans.front();
	    ans.pop();
	}
    }
};
