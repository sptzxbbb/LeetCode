// soj: 4086. 韩信点兵
// Fri Dec 12, 2014--------Shawn Chow
#include "iostream"
using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  while (n--) {
    int a, b ,c, ans = 0;
    cin >> a >> b >> c;
    for (int i = 10; i <= 100; ++i) {
      if (i % 3 == a && i % 5 == b && i % 7 == c) {
	ans = i;
	break;
      }
    }
    if (ans) cout << ans << endl;
    else cout << "No answer" << endl;
  }
  return 0;
}

