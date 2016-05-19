// soj: 1712. Parity
// Tue Dec 16, 2014--------Shawn Chow
#include "iostream"
#include "string"
using namespace std;

int main(int argc, char *argv[]) {
  string s;
  while (cin >> s, s != "#") {
    int numOfOne = 0;
    for (int i = 0; i < s.size(); ++i) {
      if ('1' == s[i]) ++numOfOne;
    }
    if ('e' == s[s.size() - 1]) {
      if (numOfOne % 2 != 0) s[s.size() - 1] = '1';
      else s[s.size()- 1] = '0';
    }
    if ('o' == s[s.size() - 1]) {
      if (numOfOne % 2 != 0) s[s.size() - 1] = '0';
      else s[s.size() - 1] = '1';
    }
    cout << s << endl;
  }
  return 0;
}
