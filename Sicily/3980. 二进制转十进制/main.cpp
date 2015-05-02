// soj: 3980. 二进制转十进制
// Fri Dec 12, 2014--------Shawn Chow
#include "iostream"
#include "string"
using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  while (n--) {
    int ans = 0, weight = 1;
    string s;
    cin >> s;
    for (int i = s.size() - 1; i >= 0; --i) {
      ans += weight * (s[i] - '0');
      weight *= 2;
    }
    cout << ans << endl;
  }
  return 0;
}
