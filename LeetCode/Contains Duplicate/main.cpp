#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        if (0 == size) {
            return false;
        }
        int pre = nums[0];
        for (int i = 1; i < size; i++) {
            if (pre == nums[i]) {
                return true;
            }
            pre = nums[i];
        }
        return false;
    }
};
