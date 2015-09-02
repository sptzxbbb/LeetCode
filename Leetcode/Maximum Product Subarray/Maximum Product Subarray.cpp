class Solution {
public:
    int maxProduct(vector<int>& nums) {
    int ans = nums[0], mini = nums[0], maxn = nums[0];
    int size = nums.size();
    for (int i = 1; i < size; ++i) {
      int a = min(mini * nums[i], maxn * nums[i]);
      int b = max(mini * nums[i], maxn * nums[i]);
      mini = min(nums[i], a);
      maxn = max(nums[i], b);
      ans = max(ans, maxn);
    }
    return ans;
  }
};
