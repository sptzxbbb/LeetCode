class Solution {
  public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }
        vector<vector<bool> > match(s1.size() + 1, vector<bool>(s2.size() + 1, false));
        match[0][0] = true;
        for (int i = 1; i <= s1.size(); i++) {
            if (s1[i - 1] == s3[i - 1]) {
                match[i][0] = true;
            } else {
                break;
            }
        }
        for (int i = 1; i <= s2.size() ; i++) {
            if (s2[i - 1] == s3[i - 1]) {
                match[0][i] = true;
            } else {
                break;
            }
        }
        for (int i = 1; i <= s1.size(); i++) {
            for (int j = 1; j <= s2.size(); j++) {
                match[i][j] = ((s1[i - 1] == s3[i + j - 1] && match[i - 1][j]) ||
                               (s2[j - 1] == s3[i + j - 1] && match[i][j - 1]));
            }
        }
        return match[s1.size()][s2.size()];
    }
};


// dfs Solution, resulting TLD
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        bool ans = false;
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }
        dfs(s1, s2, s3, 0, 0, 0, ans);
        return ans;
    }
    void dfs(string& s1, string& s2, string& s3, int i, int j, int k, bool& ans) {
        if (k == s3.size()) {
            ans = true;
            return;
        }
        if (i < s1.size() && j < s2.size() && s3[k] != s1[i] && s3[k] != s2[j]) {
            return;
        }
        if (i < s1.size() && s3[k] == s1[i]) {
            dfs(s1, s2, s3, i + 1, j, k + 1, ans);
        }
        if (ans == true) {
            return;
        }
        if (j < s2.size() && s3[k] == s2[j]) {
            dfs(s1, s2, s3, i, j + 1, k + 1, ans);
        }
        return;
    }
};