#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        bool visit[nums.size()];
        memset(visit, false, sizeof(visit));
        vector<int> v;
        vector<vector<int> > ans;
        dfs(visit, nums, v, ans, 0, nums.size());
        return ans;
    }
    void dfs(bool visit[], vector<int>& nums, vector<int>& v, vector<vector<int> >&ans, int position, int size) {
        if (position == size) {
            ans.push_back(v);
            return;
        }
        if (0 == position ||
            nums[position] != nums[position - 1] ||
            (nums[position] == nums[position - 1] && true == visit[position - 1])) {
            visit[position] = true;
            v.push_back(nums[position]);
            dfs(visit, nums, v, ans, position + 1, size);
            v.pop_back();
            visit[position] = false;
        }

        dfs(visit, nums, v, ans, position + 1, size);
        return;
    }
};

int main(int argc, char *argv[]) {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    Solution k;
    k.subsetsWithDup(nums);
    return 0;
}

