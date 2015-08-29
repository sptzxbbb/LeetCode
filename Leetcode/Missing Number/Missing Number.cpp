class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        for (auto i : nums ) {
            sum += i;
        }
        int n = nums.size();
        return n * (n + 1) / 2 - sum;
    }
};