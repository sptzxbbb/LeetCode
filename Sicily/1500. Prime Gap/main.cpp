// soj: 1500. Prime Gap
// Sun Nov 30, 2014--------Shawn Chow

#include "iostream"
#include "cstring"
using namespace std;

const int MAX = 1300000;  // a million
bool is_prime[MAX];
int prime[MAX / 10];

int primelist() {
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
  return size;
}

int binarysearch(int i, int j, int key) {
  for (int k = 1; k < j; ++k) {
    if (prime[k] == key) return 0;
    if (prime[k] < key && prime[k + 1] > key) return prime[k + 1] - prime[k];
  }
}

int main(int argc, char *argv[]) {
  int k, size;
  size = primelist();
  cout << size << endl;
  cin >> k;
  while (k) {
    int ans;
    ans = binarysearch(1, size, k);
    cout << ans << endl;
    cin >> k;
  }
  return 0;
}
