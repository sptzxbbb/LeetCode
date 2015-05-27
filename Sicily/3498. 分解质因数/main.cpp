// soj: 3498. 分解质因数
// Sun Nov 30, 2014--------Shanw Chow
#include "iostream"
#include "cstring"
using namespace std;

const int MAX = 1000000;  // a million
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
  primelist();
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int count = 1;
    while (n != 1) {
      if (n % prime[count] == 0) {
	cout << prime[count] << ' ';
	n /= prime[count];
      } else {
	++count;
      }
    }
    cout << endl;
  }
  return 0;
}
