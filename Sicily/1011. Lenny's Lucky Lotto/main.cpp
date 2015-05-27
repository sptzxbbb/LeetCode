// soj : 1011. Lenny's Lucky Lotto
// Wed Dec 24, 2014--------Shawn Chow
#include "iostream"
#include "cstring"
using namespace std;

long long list[11][2001], ans, N, M, C;

int main(int argc, char *argv[]) {
  int count;
  cin >> C;
  count = C;
  while (C--) {
    ans = 0;
    memset(list, 0, sizeof(list));
    cin >> N >> M;
    for (int i = 1; i <= M; ++i) {
      list[1][i] = 1;
    }
    for (int i = 2; i <= N; ++i) {
      for (int j = 1; j <= M; ++j) {
        for (int k = 1; k <= j / 2; ++k) {
          list[i][j] += list[i - 1][k];
        }
      }
    }
    for (int i = 1; i <= M; ++i) {
      ans += list[N][i];
    }
    cout << "Case " << count - C << ": n = " << N
         << ", m = " << M << ", # lists = " << ans << endl;
  }
  return 0;
}
