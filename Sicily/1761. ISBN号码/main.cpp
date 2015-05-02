// soj: 1761. ISBN号码
// Tue Dec 16, 2014--------Shawn Chow
#include "iostream"
#include "string"
using namespace std;

int main(int argc, char *argv[]) {
  string s;
  while (cin >> s) {
    int ans = 0;
    bool a = false;
    ans = (s[0] - '0') * 1;

    for (int i = 2; i < 5; ++i) {
      ans += (s[i] - '0') * i;
    }

    for (int i = 5; i < 10; ++i) {
      ans += (s[i + 1] - '0') * i;
    }

    ans %= 11;
    
    if (10 == ans) {
      if ('X' == s[s.size() - 1]) a = true;
      else s[s.size() - 1] = 'X';
    } else {
      if (ans == (s[s.size() - 1] - '0')) a = true;
      else s[s.size() - 1] = '0' + ans;
    }

    if (a) cout << "Right" << endl;
    else cout << s << endl;
  }
  return 0;
}
