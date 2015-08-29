// brute force
class Solution {
public:
    bool isMatch(string s, string p) {
        return dfs(s, p, 0, 0);
    }
    bool dfs(string s, string p, int i, int j) {
        if (j == p.size()) {
            return i == s.size();
        }
        if (j == p.size() - 1 || p[j + 1] != '*') {
            if (i < s.size() && (s[i] == p[j] || s[i] == '.' || p[j] == '.')) {
                return dfs(s, p, i + 1, j + 1);
            } else {
                return false;
            }
        } else {
            // p[j + 1] == '*';
            while (i < s.size() && (p[j] == '.' || s[i] == p[j])) {
                if (dfs(s, p, i, j + 2)) {
                    return true;
                }
                ++i;
            }
            return dfs(s, p, i, j + 2);
        }
    }
};

// DP Solution
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool> > dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] != '.' && p[j - 1] != '*') {
                    if (i > 0 && s[i - 1] == p[j - 1] && dp[i - 1][j - 1]) {
                        dp[i][j] = true;
                    }
                } else if (p[j - 1] == '.') {
                    if (i > 0 && dp[i - 1][j - 1]) {
                        dp[i][j] = true;
                    }
                } else if (p[j - 1] == '*') {
                    if (dp[i][j - 1] || dp[i][j - 2]) {
                        dp[i][j] = true;
                    } else if (i > 0 && (p[j - 2] == s[i - 1] || p[j - 2] == '.') && dp[i - 1][j]) {
                        dp[i][j] = true;
                    }
                }
            }
        }
        return dp[m][n];
    }
};