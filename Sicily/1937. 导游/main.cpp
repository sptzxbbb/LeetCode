// soj: 1937. 导游
// Sat Dec 27, 2014--------Shawn Chow
#include "iostream"
#include "algorithm"
using namespace std;

const int MAX = -1;
int map[101][101];  // why it is global

int main(int argc, char *argv[]) {
  int n, m, q;
  cin >> q;
  while(q--) {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        map[i][j] = MAX;
        if (i == j) map[i][j] = 0;
      }
    }

    int a, b, x;
    for (int i = 0; i < m; ++i) {
      cin >> a >> b >> x;
      map[a][b] = x;
      map[b][a] = x;
    }

    int s, d, t;
    cin >> s >> d >> t;

    for (int k = 1; k <= n; ++ k) {
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
          map[i][j] = max(map[i][j], min(map[i][k], map[k][j]));
        }
      }
    }
    if (t % (map[s][d] - 1) == 0) cout << t / (map[s][d] - 1) << endl;
    else cout << t / (map[s][d] - 1) + 1 << endl;
  }
  return 0;
}
