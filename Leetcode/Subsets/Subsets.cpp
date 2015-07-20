class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int> > ans;
        vector<int> v;
        sort(nums.begin(), nums.end());
        dfs(ans, v, 0, size, nums);
        return ans;
    }
    void dfs(vector<vector<int> >& ans, vector<int>& v, int position, int size, vector<int>& nums) {
        if (position == size) {
            ans.push_back(v);
            return;
        }
        v.push_back(nums[position]);
        dfs(ans, v, position + 1, size, nums);
        v.pop_back();
        dfs(ans, v, position + 1, size, nums);
        return;
    }
};