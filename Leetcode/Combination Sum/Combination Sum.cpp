class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > result;
        vector<int> v;
        sort(candidates.begin(), candidates.end());
        int sum = 0, start = 0;
        dfs(result, v, candidates, target, sum, start);
        return result;
    }

    void dfs(vector<vector<int> >& result, vector<int>& v, vector<int>& candidates, int target, int sum, int start) {
        if (sum >= target) {
            if (sum == target) {
                result.push_back(v);
            }
            return;
        }
        int size = candidates.size();
        for (int i = start; i < size; i++) {
            sum += candidates[i];
            v.push_back(candidates[i]);
            dfs(result, v, candidates, target, sum, i);
            v.pop_back();
            sum -= candidates[i];
        }
        return;
    }
};