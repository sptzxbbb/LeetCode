class Solution {
  public:
    // dp solution
    int numSquares(int n) {
        vector<int> dp(n + 1);
        fill(dp.begin(), dp.end(), INT_MAX);
        for (int i = 0; i * i <= n; i++) {
            dp[i * i] = 1;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; i + j * j <= n; j++) {
                dp[i + j * j] = min(dp[i + j * j], dp[i] + 1);
            }
        }
        return dp[n];
    }
};

class Solution {
  public:
    int numSquares(int n) {
        int ub = sqrt(n);
        for (int a=0; a<=ub; ++a) {
            for (int b=a; b<=ub; ++b) {
                int c = sqrt(n - a*a - b*b);
                if (a*a + b*b + c*c == n)
                return !!a + !!b + !!c;
            }
        }
        return 4;
    }
};