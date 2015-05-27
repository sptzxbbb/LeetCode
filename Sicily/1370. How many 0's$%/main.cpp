// soj: 1370. How many 0's?
// Thu Dec 11, 2014--------Shawn Chow
#include "iostream"
using namespace std;

int zero(int a);

int main(int argc, char *argv[]) {
  int m, n, k;
  makeTable();
  while (cin >> m >> n, m >= 0) {
    int ans = 0;
    for (int i = m; i <= n; ++i) {
      ans += zero(i);
    }

    cout << ans << endl;
  }
  return 0;
}

int zero(int a) {
  int ans = 0, reminder;
  do {
    reminder = a % 10;
    a /= 10;
    if (0 == reminder) ++ans;
  } while (a);
  return ans;
}
