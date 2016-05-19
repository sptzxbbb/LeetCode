class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int size = nums.size();
        unordered_set<int> s;
        for (int i = 0; i < size; i++) {
            s.insert(nums[i]);
        }
        int max_length = 0;
        for (int i = 0; i < size; i++) {
            if (s.find(nums[i]) != s.end()) {
                int length = 1;
                int next = nums[i] - 1;
                s.erase(nums[i]);
                while (s.find(next) != s.end()) {
                    s.erase(next);
                    ++length;
                    --next;
                }
                next = nums[i] + 1;
                while (s.find(next) != s.end()) {
                    s.erase(next);
                    ++length;
                    ++next;
                }
                max_length = max(max_length, length);
            }
        }
        return max_length;
    }
};