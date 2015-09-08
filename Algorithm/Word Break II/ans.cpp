class Solution {
public:
    bool isWordBreak(string& s, unordered_set<string>& wordDict) {
        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;
        int minlen = INT_MAX;
        int maxlen = INT_MIN;
        for (string word : wordDict) {
            minlen = min(minlen, (int)word.length());
            maxlen = max(maxlen, (int)word.length());
        }
        for (int i = 1; i <= s.length(); i++) {
            for (int j = i - minlen; j >= max(0, i - maxlen); j--) {
                if (dp[j] && wordDict.find(s.substr(j, i - j)) != wordDict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }
    void breakWords(string s, int idx, unordered_set<string>& wordDict, string& sol, vector<string>& res) {
        if (idx == s.length()) {
            sol.resize(sol.length() - 1);
            res.push_back(sol);
            return;
        }
        for (int i = idx; i < s.length(); i++) {
            string word = s.substr(idx, i - idx + 1);
            if (wordDict.find(word) != wordDict.end()) {
                string tmp = sol;
                sol += word + " ";
                breakWords(s, i + 1, wordDict, sol, res);
                sol = tmp;
            }
        }
    }
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        string sol;
        vector<string> res;
        if (!isWordBreak(s, wordDict)) return res;
        breakWords(s, 0, wordDict, sol, res);
        return res;
    }
};