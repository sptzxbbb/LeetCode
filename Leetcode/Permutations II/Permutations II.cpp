class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int>& nums) {
        vector<int> a;
        int n = nums.size();
        bool *check = new bool[n];
        memset(check, 0, sizeof(check));
        sort(nums.begin(), nums.end());
        ans.clear();
        getPermu(nums, a, 0, n, check);
        delete[] check;
        return ans;
    }
    void getPermu(vector<int>& nums, vector<int>& a, int 2position, int n, bool* check) {
        if (position == n) {
            ans.push_back(a);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (false == check[i]) {
                if (i > 0 && nums[i] == nums[i - 1] && false == check[i - 1]) {
                    continue;
                }
                check[i] = true;
                a.push_back(nums[i]);
                getPermu(nums, a, position + 1, n, check);
                a.pop_back();
                check[i] = false;
            }

        }
        return;
    }
private:
    vector<vector<int> > ans;
};

