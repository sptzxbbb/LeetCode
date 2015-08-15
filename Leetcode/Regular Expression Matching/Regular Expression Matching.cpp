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
        }
        // p[j + 1] == '*';
        while (i < s.size() && (p[j] == '.' || s[i] == p[j])) {
            if (dfs(s, p, i, j + 2)) {
                return true;
            }
            ++i;
        }
        return dfs(s, p, i, j + 2);
    }
};