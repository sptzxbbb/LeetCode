// soj: 1765. 笨小猴
// Fri Dec 12, 2014--------Shawn Chow
#include "string"
#include "iostream"
using namespace std;

bool prime(int a) {
  if (a <= 1) return false;
  for (int i = 2; i * i <= a; ++i) {
    if (a % i == 0) return false;
  }
  return true;
}

int main(int argc, char *argv[]) {
  string s;
  while (cin >> s) {
    int letter[26] = {0}, max = 0, min = 100, ans;
    for (int i = 0; i < s.size(); ++i) {
      ++letter[s[i] - 'a'];
    }
    for (int i = 0; i < 26; ++i) {
      if (letter[i] > max) max = letter[i];
      if (letter[i] < min && letter[i]) min = letter[i];
    }
    
    if (max == s.size()) min = max;
    ans = max - min;
    if (prime(ans)) {
      cout << "Lucky Word" << endl << ans << endl;
    } else {
      cout << "No Answer" << endl << '0' << endl;
    }
  }
  return 0;
}
