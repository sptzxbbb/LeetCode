class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> value;
        vector<int> result;
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            value[nums[i]] = i;
        }
        for (int i = 0; i < size; i++) {
            int k = target - nums[i];
            unordered_map<int, int>::iterator it;
            it = value.find(k);
            if (it != value.end() && it->second != i) {
                result.push_back(i + 1);
                result.push_back(value[k] + 1);
                break;
            }
        }
        return result;
    }
};


