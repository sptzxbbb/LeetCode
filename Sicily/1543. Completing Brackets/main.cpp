// soj: 1543. Completing Brackets
// Mon Dec 12, 2014--------Shawn Chow
#include "iostream"
#include "string"
#include "stack"
using namespace std;

int main(int argc, char *argv[]) {
  string s;
  while (cin >> s) {
    stack<char> bracket;
    string ans;

    for (int i = 0; i < s.size(); ++i) {
      if ('[' == s[i]) bracket.push('[');
      if (']' == s[i]) {
	if (bracket.empty() ||
	    (!bracket.empty() && bracket.top() == ']'))
	    bracket.push(']');
	if (!bracket.empty() && bracket.top() == '[') bracket.pop();
      }
    }

    while (!bracket.empty()) {
      if (bracket.top() == '[') s += ']';
      if (bracket.top() == ']') s = '[' + s;
      bracket.pop();
    }
    cout << s << endl;
  }
  return 0;
}
