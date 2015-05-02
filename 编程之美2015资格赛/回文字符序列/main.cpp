#include "iostream"
#include "string"
#include "cstring"
using namespace std;

const int mod = 100007;
int main(int argc, char *argv[]) {
    int t, n = 0;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int ans = 0, size = s.size();
		int dp[s.size()][s.size()];
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < size; ++i) {
			dp[i][i] = 1;
		}
		
		for (int i = 1; i < size; ++i) {
			for (int j = i - 1; j >= 0; --j) {
				dp[j][i] = dp[j +1][i] + dp[j][i - 1] - dp[j + 1][i - 1];
				if (s[i] == s[j]) {
					dp[j][i] = (dp[j][i] + dp[j + 1][i - 1] + 1) % mod;
				}
			}
		}
		cout << "Case #" << ++n << ": " << dp[0][size - 1] << endl;
	}
    return 0;
}
