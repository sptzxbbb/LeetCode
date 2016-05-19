// soj: 1006. Team Rankings
// Thu Dec 25, 2014--------Shawn Chow
#include "iostream"
#include "string"
#include "algorithm"
using namespace std;

int median(string a, string b) {
  int diff = 0, o1, o2;
  for (int i = 0; i < 4; ++i) {
    for (int j = i + 1; j < 5; ++j) {
      for (int k = 0; k < 5; ++k) {
        if (b[k] == a[i]) o1 = k;
        if (b[k] == a[j]) o2 = k;
      }
      if (o2 < o1) ++diff;
    }
  }
  return diff;
}

int main(int argc, char *argv[]) {
  string rank[120], s = "ABCDE";
  int diff[120];
  rank[0] = s;
  for (int i = 1; next_permutation(s.begin(), s.end()); ++i) {
    rank[i] = s;
  }

  int n;
  while (cin >> n, n != 0) {
    string p[n];
    for (int i = 0; i < n; ++i) {
      cin >> p[i];
    }

    int min = 9999999, cur;
    string ans;
    for (int i = 0; i < 120; ++i) {
      cur = 0;
      for (int j = 0; j < n; ++j) {
        cur += median(rank[i], p[j]);
      }
      if (min > cur) {
        ans = rank[i];
        min = cur;
      }
    }
    cout << ans << " is the median ranking with value " << min << '.' << endl;
  }

  return 0;
}

