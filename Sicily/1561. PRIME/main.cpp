// soj: 1561. PRIME
// Sun Nov 30, 2014--------Shawn Chow
#include "iostream"
#include "cstring"
using namespace std;

const int MAX = 1300000;  // a million
bool is_prime[MAX];
int prime[MAX / 10];

void primelist() {
  int size = 0;
  memset(is_prime, true, sizeof(is_prime));
  for (int i = 2; i <= MAX; ++i) {
    if (is_prime[i]) {
      prime[++size] = i;
      if (i * i <= MAX) {
	for (int j = 2 * i ; j <= MAX ; j += i) {
	  is_prime[j] = false;
	}
      }
    }
  }
}

int main(int argc, char *argv[]) {
  int k;
  cin >> k;
  primelist();
  cout << prime[k] << endl;
  return 0;
}
