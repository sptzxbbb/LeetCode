class Solution {
public:
    vector<vector<int> > combinationSum3(int k, int n) {
        vector<int> s;
        vector<vector<int> > result;
        dfs(k, n, 1, result, s);
        return result;
    }

    void dfs(int k, int n, int min_num, vector<vector<int> >& result, vector<int> s) {
        if (1 == k) {
            if (n <= 9 && min_num <= n) {
                s.push_back(n);
                result.push_back(s);
                s.pop_back();
            }
            return;
        }

        for (int i = min_num; i <= min(n, 9); i++) {
            s.push_back(i);
            dfs(k - 1, n - i, i + 1, result, s);
            s.pop_back();
        }
    }
};

