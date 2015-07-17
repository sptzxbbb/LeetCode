class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<int> v;
        vector<vector<int> > ans;
        dfs(ans, v, k, 1, n);
        return ans;
    }

    void dfs(vector<vector<int> >& ans, vector<int>& v, int k, int min_num, int n) {
        if (0 == k) {
            ans.push_back(v);
            return;
        }
        for (int i = min_num; i <= n && i + k - 1 <= n; i++) {
            v.push_back(i);
            dfs(ans, v, k - 1, min_num + 1, n);
            v.pop_back();
        }

        return;
    }
};
