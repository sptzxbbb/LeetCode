// soj: 1221. 数字游戏
// Wed Dec 7, 2014--------Shawn Chow
#include "iostream"
#include "algorithm"
#include "cstring"
using namespace std;

struct node {
  int value;
  int decrement;
};

bool cmp(node a, node b);

int main(int argc, char *argv[]) {
  int n, m;
  cin >> n >> m;
  node num[n];
  int ans[m + 1];
  memset(ans, 0, sizeof(ans));
  for (int i = 0; i < n; ++i) {
    cin >> num[i].value;
  }
  for (int i = 0; i < n; ++i) {
    cin >> num[i].decrement;
  }

  sort(num, num + n, cmp);

  for (int i = 0; i < n; ++i) {
    for (int j = m; j >= 1; --j) {
      ans[j] = max(ans[j], ans[j - 1] + num[i].value - (j - 1) * num[i].decrement);
    }
  }

  cout << ans[m] << endl;
  return 0;
}

bool cmp(node a, node b) {
  if (a.decrement > b.decrement) return true;
  return false;
}


