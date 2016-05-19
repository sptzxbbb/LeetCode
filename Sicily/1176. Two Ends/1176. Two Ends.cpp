#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
  public:
    void gameOn(void) {
        int n, turn = 1;
        while (cin >> n && n != 0) {
            int sum = 0;
            vector<int> card(n + 1, 0);
            vector<vector<int> > dp;
            dp.push_back(vector<int>(1, 0));
            for (int i = 1; i <= n; i++) {
                cin >> card[i];
                sum += card[i];
                dp.push_back(vector<int>(i + 1, 0));
                dp[i][i - 1] = max(card[i - 1], card[i]);
            }
            for (int i = n - 3; i >= 1; i--) {
                for (int j = i + 3; j <= n; j += 2) {
                    // take card[i]
                    dp[j][i] = card[i + 1] >= card[j] ? (dp[j][i + 2] + card[i]) : (dp[j - 1][i + 1] + card[i]);
                    // take card[j]
                    dp[j][i] = card[i] >= card[j - 1] ? max(dp[j][i], dp[j - 1][i + 1] + card[j]) : max(dp[j][i], dp[j - 2][i] + card[j]);
                }
            }
            cout << "In game " << turn++ << ", the greedy strategy might lose by as many as "
                 << 2 * dp[n][1] - sum << " points." << endl;
        }
        return;
    }
};

int main(int argc, char *argv[]) {
    Solution k;
    k.gameOn();
    return 0;
}

