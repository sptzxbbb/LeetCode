class Solution {
public:
    bool isMatch(string s, string p) {
        // dp[i][j] : whether s[0, i] and p[0, j] is matched or not
        // if s[i] == '*', dp[i][j...p.size()-1]
        bool dp[s.size()][p.size()] = {false};

        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < p.size(); j++) {
                if (dp[i - 1][j - 1] &&
                    (s[i] == p[j] || s[i] == '?' || p[j] == '?')) {
                    dp[i][j] = true;
                }

            }
        }
    }
};