class Solution {
public:
    bool isMatch(string s, string p) {
        // dp[i][j] : whether s[0, i) and p[0, j) is matched or not
        bool dp[s.size()][p.size()] = {false};
        dp[0][0] = true;
        if (s[0] == '*') {
            dp[1][0] = true;
        }
        if (p[0] == '*') {
            dp[0][1] = true;
        }

        for (int i = 2; i <= s.size(); i++) {
            for (int j = 2; j <= p.size(); j++) {
                if ((singleMatch(s[i - 1], p[j - 1] && dp[i - 1][j - 1])) ||
                    (p[j - 1] == '*' && dp[i][j - 1])) {
                    dp[i][j] = true;
                }
            }
        }
        return dp[s.size()][p.size()];
    }
    bool singleMatch(char a, char b) {
        if (a == '?' || b == '?' || a == b) {
            return true;
        } else {
            return false;
        }
    }
};