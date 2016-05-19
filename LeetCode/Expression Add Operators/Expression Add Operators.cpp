class Solution {
  public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        dfs(num, target, 0, 0, "", res);
        return res;
    }
    void dfs(string num, int target, long pre, long curSum, string path, vector<string>& res) {
        if (num.size() == 0 && curSum == target) {
            res.push_back(path);
            return;
        }
        for (int i = 1; i <= num.size(); i++) {
            string cur = num.substr(0, i);
            if (cur.size() > 1 && cur[0] == '0') {
                return;
            }
            string next = num.substr(i);
            if (path.size() > 0) {
                dfs(next, target, stol(cur), curSum + stol(cur), path + "+" + cur, res);
                dfs(next, target, -stol(cur), curSum - stol(cur), path + "-" + cur, res);
                dfs(next, target, pre * stol(cur), (curSum - pre) + pre * stol(cur), path + "*" + cur, res);
            } else {
                dfs(next, target, stol(cur), stol(cur), cur, res);
            }
        }
        return;
    }
};
