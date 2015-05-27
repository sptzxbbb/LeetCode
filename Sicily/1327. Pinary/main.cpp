// soj: 1327. Pinary
// Thu Dec 11, 2014--------Shawn Chow
#include "iostream"
#include "string"
using namespace std;

int main(int argc, char *argv[]) {
  int a1 = 1, a2 = 2, pos = 2;
  int table[39];
  table[1] = 1, table[2] = 2;
  while (pos != 39) {
    ++pos;
    table[pos] = a1 + a2;
    a1 = a2;
    a2 = table[pos];
  }

  int k;
  cin >> k;
  while (k--) {
    int n, pos = 38;
    bool first = false;
    string ans;
    cin >> n;
    for (int i = 38; i >= 1; --i) {
      if (n >= table[i]) {
	n -= table[i];
	first = true;
	ans += '1';
      } else if (first && n < table[i]) {
	ans += '0';
      }
    }
    cout << ans << endl;
  }
  return 0;
}

// 1  10  100  101  1000 1001  1010 10000  10001 10010 10100
// 1   2    3    4     5    6     7     8      9    10    11

// 10101  100000
//    12      13

// 1 2 3 5 8 13
