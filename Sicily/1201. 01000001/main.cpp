// soj: 1201. 01000001
// Thu Dec 4, 2014
#include "iostream"
#include "string"
#include "algorithm"
using namespace std;

int main(int argc, char *argv[]) {
  int n, ans = 1;
  cin >> n;
  while (n--) {
    string s1, s2, temp;
    cin >> s1 >> s2;
    if (s1.size() < s2.size()) {
      swap(s1, s2);
    }

    int padding = s1.size() - s2.size();
    bool non_zero = false; // leading zero, for like 000010
    for (int i = 0; i < padding; ++i) {
      s2 = "0" + s2;
    }

    int carry = 0, length = s1.size();
    for (int i = length - 1; i >= 0; --i) {
      s1[i] = s1[i] + (s2[i] - '0') + carry;
      carry = 0;
      if ('2' == s1[i] || '3' == s1[i]) {
	s1[i] -= 2;
	carry = 1;
      }
    }
    if (carry) s1 = "1" + s1; // the leading carry
    
    cout << ans << ' ';
    for (int i = 0; i < s1.size(); ++i) {
      if ('0' != s1[i] && false == non_zero) non_zero = true;
      if (non_zero) cout << s1[i];
    }
    
    if (!non_zero) cout << '0'; // 000 + 00000
    cout << endl;
    
    ans++;
  }
  return 0;
}


