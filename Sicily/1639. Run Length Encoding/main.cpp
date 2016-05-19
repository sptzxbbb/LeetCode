// soj: 1639. Run Length Encoding
// Fri Dec 12, 2014--------Shawn Chow
#include "iostream"
#include "string"
using namespace std;

int main(int argc, char *argv[]) {
  string s;
  while (getline(cin, s)) {
    int num = 0, size = 0;
    string ans;
    if (s == "") {
      cout << endl;
      continue;
    }
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] >= '0' && s[i] <= '9') {
	num = num * 10 + s[i] - '0';
	if (num > 50 || ans.size() > 50) {  // exceed size of 50
	  size = 51;
	  break;
	}
      } else {  // add the letter into ans
	if (num) {  // with coefficient
	  while (num) {
	    ans += s[i];
	    --num;
	  }
	} else {  // without coefficient
	  ans += s[i];
	}
      }
    }
    if (!size) size = ans.size();
    if (size > 50) ans = "TOO LONG";
    cout << ans << endl;
  }
  return 0;
}
