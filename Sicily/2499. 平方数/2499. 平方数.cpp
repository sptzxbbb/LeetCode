#include <iostream>
#include <vector>
using namespace std;
const int SIZE = 60000;
vector<int> dp(SIZE + 1);

class Solution {
  public:
    // dp solution
    void numSquares(int n) {
        fill(dp.begin(), dp.end(), 4);
        for (int i = 0; i * i <= n; i++) {
            dp[i * i] = 1;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; i + j * j <= n; j++) {
                dp[i + j * j] = min(dp[i + j * j], dp[i] + 1);
            }
        }
    }
};

int main(int argc, char *argv[]) {
    // calc table
    Solution k;
    k.numSquares(SIZE);
    int n;
    cin >> n;

    while (n--) {
        int a;
        cin >> a;
        cout << dp[a] << endl;
    }
    return 0;
}
