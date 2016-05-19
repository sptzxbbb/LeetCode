// soj: 3836. 计算组合数
// Fri Dec 12, 2014--------Shawn Chow
#include "iostream"
using namespace std;

int main(int argc, char *argv[]) {
  int n, m;
  while (cin >> m >> n, m != 0) {
    int ans = 1;
    for (int i = m; i >= m - n + 1; --i) {
      ans *= i;
    }
    for (int i = n; i >= 1; --i) {
      ans /= i;
    }
    cout << ans << endl;
  }
  return 0;
}
