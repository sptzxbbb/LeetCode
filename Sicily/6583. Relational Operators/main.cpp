// soj: 6583. Relational Operators
// Thu Dec 25, 2014--------Shawn Chow
#include "iostream"
#include "string"
using namespace std;

int main(int argc, char *argv[]) {
  int a, b, count = 1;
  string s;
  while (cin >> a >> s >> b, s != "E") {
    cout << "Case " << count << ": ";
    if (">" == s) {
      if (a > b) cout << "true" << endl;
      else cout << "false" << endl;
    } else if (">=" == s) {
      if (a >= b) cout << "true" << endl;
      else cout << "false" << endl;
    } if ("<" == s) {
      if (a < b) cout << "true" << endl;
      else cout << "false" << endl;
    } if ("<=" == s) {
      if (a <= b) cout << "true" << endl;
      else cout << "false" << endl;
    } if ("==" == s) {
      if (a == b) cout << "true" << endl;
      else cout << "false" << endl;
    } if ("!=" == s) {
      if (a != b) cout << "true" << endl;
      else cout << "false" << endl;
    }
    ++count;
  }
  return 0;
}
