// soj: 1491. Look and Say
// Thu Dec 11, 2014--------Shawn Chow
#include "iostream"
#include "string"
#include "cstdio"
using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  while (n--) {
    string s, ans;
    cin >> s;
    int num = 1;
    char buf[10];
    for (int i = 1; i < s.size(); ++i) {
      if (s[i - 1] == s[i]) {
	++num;
      } else {
	sprintf(buf, "%d", num);
	ans += buf;
	ans += s[i - 1];
	num = 1;
      }
    }
    sprintf(buf, "%d", num);
    ans += buf;
    ans += s[s.size() - 1];
    cout << ans << endl;
  }

  return 0;
}
