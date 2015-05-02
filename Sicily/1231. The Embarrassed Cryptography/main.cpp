// soj: 1231. The Embarrassed Cryptography
// Mon Dec 8, 2014--------Shawn Chow
#include "iostream"
#include "string"
#include "cstring"
using namespace std;

const int SIZE = 1000001;
bool prime[SIZE + 1];

bool mod(string s, int m);
void PrimeTable();

int main(int argc, char *argv[]) {
  int L, ok, ans;
  string K;
  PrimeTable();
  while (cin >> K >> L, K != "0") {
    ok = 1;
    
    if (mod(K, 2) && 2 < L) {
      ans = 2;
      ok = 0;
    } else {
      for (int i = 3; i <= SIZE; i += 2) {
	if (prime[i] && mod(K, i)) {
	  if (i < L) {
	    ans = i;
	    ok = 0;
	  }
	  break;
	}
      }
    }
    if (ok) cout << "GOOD" << endl;
    else cout << "BAD " << ans << endl; 
  }
  return 0;
}

bool mod(string s, int m) {
  int size = s.size(), ans = 0;
  for (int i = 0; i < size; ++i) {
    ans = (ans * 10 + s[i]- '0') % m;
  }
  if (!ans) return true;
  else return false;
}

void PrimeTable() {
  memset(prime, true, sizeof(prime));
  int n = 2;
  for (int i = 2; i * i <= SIZE; ++i) {
    if (prime[i]) {
      n = 2 * i;
      while (n <= SIZE) {
	prime[n] = false;
	n += i;
      }
    }
  }
}                                 
