// soj: 1388. Quicksum
// Thu Dec 11, 2014--------Shawn Chow
#include "iostream"
#include "string"
using namespace std;

int main(int argc, char *argv[]) {
  string s;
  while (getline(cin, s), s != "#") {
    int ans = 0;
    for (int i = 1; i <= s.size(); ++i) {
      if (s[i - 1] != ' ') ans += i * (s[i - 1] - 'A' + 1);
    }
    cout << ans << endl;
  }

  return 0;
}


// AB CDEFG HIJKLMNOPQRSTUVWXYZ
