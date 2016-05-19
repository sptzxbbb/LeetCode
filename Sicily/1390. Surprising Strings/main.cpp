// soj: 1390. Surprising Strings
// Thu Dec 11, 2014--------Shawn Chow
#include "iostream"
#include "string"
#include "set"
using namespace std;

int main(int argc, char *argv[]) {
  string s, temp;
  while (cin >> s, s != "*") {
    bool surprise = true;
    int size = s.size() - 3;
    for (int i = 0; i <= size; ++i) {
      set<string> pairs;
      int p = 0;
      while (p + i + 1 <= s.size() - 1) {
	temp = s[p];
	temp += s[p + i + 1];
	if (pairs.find(temp) == pairs.end()) {
	  pairs.insert(temp);
	} else {
	  surprise = false;
	  break;
	}
	p++;
      }
      if (!surprise) break;
    }
    
    if (surprise) cout << s << " is surprising." << endl;
    else cout << s << " is NOT surprising." << endl;
  }
  return 0;
}


