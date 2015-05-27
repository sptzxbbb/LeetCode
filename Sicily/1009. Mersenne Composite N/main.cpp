// soj: 1009. Mersenne Composite N
// Thu Dec 25, 2014--------Shawn Chow
#include "iostream"
#include "cmath"
using namespace std;

bool prime(long long m) {
  if (m % 2 == 0) return false;
  for (long long i = 3; i * i <= m; i += 2) {
    if (m % i == 0) return false;
  }
  return true;
}

int main(int argc, char *argv[]) {
  int t;
  cin >> t;
  for (int j = 3; j < t; j += 2) {
    if (!prime(j)) continue;
    long long s = pow(2, j) - 1, s2 = s;
    bool b = false, b2 = false;
    for (long long i = 3; i * i <= s; i += 2) {
      if (s % i == 0 && prime(i)) {
        if (!b2) cout << i;
        else cout << " * " << i;
        s /= i;
        i = 3;
        b2 = true;
        b = true;
      }
    }
    if (b) {
      cout << " * " << s << " = " << s2 << " = ( 2 ^ " << j << " ) - 1" << endl;
    }
  }
  return 0;
}
