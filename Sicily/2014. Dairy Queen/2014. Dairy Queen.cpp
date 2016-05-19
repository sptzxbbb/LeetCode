#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
    int N, C;
    cin >> N >> C;
    vector<int> value(C), dp(N + 1, 0);
    for (int i = 0; i < C; i++) {
        cin >> value[i];
    }
    dp[0] = 1;
    for (int i = 0; i < C; i++) {
        dp[value[i]] += 1;
        for (int j = value[i] + 1; j <= N; j++) {
            dp[j] += dp[j - value[i]];
        }
    }
    cout << dp[N] << endl;
    return 0;
}
