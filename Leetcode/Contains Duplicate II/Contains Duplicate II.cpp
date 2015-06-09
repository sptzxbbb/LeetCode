class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int> n;
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            // nums[i] != nums[j]
            if (n.find(nums[i]) != n.end()) {
                n.insert(nums[i]);
                if (n.size() > k) {
                    n.erase(n.find(nums[i - k]));
                }
            } else {
                return true;
            }
        }
        return false;
    }
};