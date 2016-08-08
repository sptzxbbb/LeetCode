class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        auto it = wordDict.begin();
        vector<string> res, matched;
        vector<bool> possible(s.size() + 1, true);
        dfs(s, 0, possible, wordDict, res, matched);
        return res;
    }
    void dfs(string& s, int pos, vector<bool>& possible, unordered_set<string>& wordDict, vector<string>& res, vector<string>& matched) {
        if (pos == s.size()) {
            string s = matched[0];
            for (int i = 1; i < matched.size(); i++) {
                s += " " + matched[i];
            }
            res.push_back(s);
            return;
        }
        auto it = wordDict.begin();
        while (it != wordDict.end()) {
            string str = (*it);
            if (str.size() + pos - 1 < s.size() &&
                s.substr(pos, str.size()) == str &&
                possible[pos + str.size()]) {
                int before = res.size();
                matched.push_back(str);
                dfs(s, pos + str.size(), possible, wordDict, res, matched);
                matched.pop_back();
                if (before == res.size()) {
                    possible[pos + str.size()] = false;
                }
            }
            ++it;
        }
        return;
    }
};