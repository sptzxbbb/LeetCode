class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        map<string, bool> visit;
        auto it = wordDict.begin();
        while (it != wordDict.end()) {
            visit[(*it)] = false;
            ++it;
        }
        vector<string> res, matched;
        dfs(s, 0, visit, wordDict, res, matched);
        return res;
    }
    void dfs(string& s, int pos, map<string, bool>& visit, unordered_set<string>& wordDict, vector<string>& res, vector<string>& matched) {
        if (pos == 0) {
            string s = matched[matched.size() - 1];
            for (int i = matched.size() - 2; i >= 0; i--) {
                s += " " + matched[i];
            }
            res.push_back(s);
            return;
        }
        auto it = wordDict.begin();
        while (it != wordDict.end()) {
            string str = (*it);
            if (pos - str.size()  < s.size() &&
                s.substr(pos, str.size()) == str) {
                visit[str] = true;
                matched.push_back(str);
                dfs(s, pos + str.size(), visit, wordDict, res, matched);
                matched.pop_back();
                visit[str] = false;
            }
            ++it;
        }
        return;
    }
};