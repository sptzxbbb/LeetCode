// soj: 1486. 统计数字
// Thu Dec 11, 2014--------Shawn Chow
#include "cstdio"
#include "iostream"
#include "map"
using namespace std;

int main(int argc, char *argv[]) {
  int n, k = 0;
  while (cin >> n) {
    long long temp;
    map<long long, int> s;

    for (int i = 0; i < n; ++i) {
      scanf("%lld", &temp);
      ++s[temp];
    }
     if (k) cout << endl;
    map<long long, int>::iterator it = s.begin(), it2 = s.end();
    while (it != it2) {
      // cout << (it->first) << ' ' << (it->second) << endl;
      printf("%lld %d\n", it->first, it->second);
      ++it;
    }
    ++k;
  }
  return 0;
}
