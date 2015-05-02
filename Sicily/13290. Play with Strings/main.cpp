// soj: 13290. Play with Strings
// Sat Dec 27, 2014--------Shawn Chow
#include "iostream"
#include "algorithm"
using namespace std;

int main(int argc, char *argv[]) {
  string a, b;
  bool ans = false;
  cin >> a >> b;
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  if (a == b) ans = true;
  // for (int i = 0; i < a.size(); ++i) {
  //   ans = false;
  //   for (int j = i; j < b.size(); ++j) {
  //     if (a[i] == b[j]) {
  //       swap(b[i], b[j]);
  //       ans = true;
  //       break;
  //     }
  //   }
  //   if (ans == false) break;
  // }
  if (ans) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
