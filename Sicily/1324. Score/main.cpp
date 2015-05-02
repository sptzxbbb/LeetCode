// soj: 1324. Score
// Sat Nov 29, 2014--------Shawn Chow
#include "iostream"
using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    int score[s.size()], ans = 0;
    for (int j = 0; j < s.size(); ++j) {
      if (0 == j) {
	if ('O' == s[j]) score[j] = 1;
	else score[j] = 0;
      } else {
	if ('O' == s[j]) {
	  if ('O' == s[j - 1]) score[j] = score[j - 1] + 1;
	  else score[j] = 1;
	} else {
	  score[j] = 0;
	}
      }
      ans += score[j];
    }
    cout << ans << endl;
  }
  return 0;
}
