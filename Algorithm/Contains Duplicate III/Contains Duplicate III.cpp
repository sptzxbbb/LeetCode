class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<int> bst;
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) {
                bst.erase(nums[i - k - 1]);
            }
            auto lb = bst.lower_bound(nums[i] - t);
            if (lb != bst.end() && abs(*lb - nums[i]) <= t) {
                return true;
            }
            bst.insert(nums[i]);
        }
        return false;
    }
};