// soj: 1817. 校歌手大奖赛
// Sun Nov 30, 2014--------Shawn Chow

#include "iostream"
#include "cstdio"
#include "algorithm"
using namespace std;

int main(int argc, char *argv[]) {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d%d", &n, &m);
    int score[n][m];
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
	scanf("%d", &score[i][j]);
      }
    }

    for (int j = 0; j < m; ++j) {
      int max = -1, min = 101;
      double ans = 0;
      for (int i = 0; i < n; ++i) {
	ans += score[i][j];
	if (score[i][j] > max) max = score[i][j];
	if (score[i][j] < min) min = score[i][j];
      }
      ans -= max + min;
      ans /= n - 2;
      printf("%.2f\n", ans);
    }
  }
  return 0;
}
