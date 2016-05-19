// soj: 1752. 选择
// Sat Nov 29, 2014--------Shawn Chow
#include "iostream"
#include "cstring"
using namespace std;

const int MAX = 100001;  // a million
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
  int low = i, high = j, mid;
  while (low <= high) {
    mid = (low + high) / 2;
    if (prime[mid] == key) return mid;
    else if (prime[mid] < key) low = mid + 1;
    else high = mid - 1;
  }
  return -1;
}

int main(int argc, char *argv[]) {
  int size = primelist();
  int w;
  cin >> w;
  while (w != -1) {
    cout << binarysearch(1, size, w) << endl;
    cin >> w;
  }
  return 0;
}




