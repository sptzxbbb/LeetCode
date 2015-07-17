class Solution {
public:
    vector<vector<int> > combinationSum3(int k, int n) {
        v.clear();
        vector<int> ans;
        int position = 0, cur_sum = 0;
        getCom(ans, position, cur_sum, k, n);
        return v;
    }

    void getCom(vector<int>& ans, int position, int cur_sum, int k, int n) {
        if (position == k) {
            if (cur_sum == n) {
                v.push_back(ans);
            }
            return;
        }
        int start = 0;
        if (ans.size()) {
            start = ans[ans.size() - 1] + 1;
        }
        for (int i = start; i <= min(9, n - cur_sum); i++) {
            ans.push_back(i);
            getCom(ans, position + 1, cur_sum + i, k, n);
            ans.pop_back();
        }
        return;
    }

private:
    vector<vector<int> > v;
};

