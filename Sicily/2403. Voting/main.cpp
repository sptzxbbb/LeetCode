// soj: 2403. Voting
// Fri Dec 12, 2014--------Shawn Chow
#include "iostream"
#include "string"
using namespace std;

int main(int argc, char *argv[]) {
  string s;
  while (cin >> s, s != "#") {
    double y, n, a, sum;
    y = n = a = 0;
    sum = s.size();
    for (int i = 0; i < sum; ++i) {
      if ('Y' == s[i]) ++y;
      if ('N' == s[i]) ++n;
      if ('A' == s[i]) ++a;
    }
    if (a >= sum / 2) {
      cout << "need quorum" << endl;
      continue;
    }
    if (y > n) {
      cout << "yes" << endl;
      continue;
    }
    if (n > y) {
      cout << "no" << endl;
      continue;
    }
    if (n == y) {
      cout << "tie" << endl;
    }
  }

  return 0;
}
