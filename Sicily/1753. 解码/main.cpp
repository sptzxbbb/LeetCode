// soj: 1753. 解码
// Sun Nov 30, 2014--------Shawn Chow

#include "iostream"
#include "string"
using namespace std;

int main(int argc, char *argv[]) {
  string s;
  cin >> s;
  while (s != "XXX") {
    int n = 0;
    string t = "";
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] < '0' || s[i] > '9') {  // character
    	t += s[i];
	cout << s[i];
      } else {  //  n following
    	n = n * 10 + s[i] - '0';
    	if (i == s.size() - 1 || (s[i + 1] < '0' || s[i + 1] > '9')) {
    	  for (int i = 0; i < n - 1; ++i) cout << t[t.size() - 1];
	  n = 0;
    	}
      }
    }
    cout << endl;
    cin >> s;
  }
  return 0;
}

