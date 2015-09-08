class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0) {
            return 0;
        }
        int dp[s.size() + 1] = {0};
        dp[0] = 1;
        dp[1] = s[0] == '0' ? 0 : 1;
        for (int i = 2; i <= s.size(); i++) {
            dp[i] = s[i - 1] != '0' ? dp[i - 1] : 0;
            int t = stoi(s.substr(i - 2, 2));
            if (t <= 26 && t >= 10) {
                dp[i] += dp[i - 2];
            }
        }
        return dp[s.size()];
    }
};