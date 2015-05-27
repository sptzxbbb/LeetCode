// soj: 4427. Greatest Common Divisors
// Fri Dec 12, 2014--------Shawn Chow
#include "iostream"
using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  while (n--) {
    long long a, b, low, high;
    bool find = false;
    cin >> a >> b >> low >> high;
    for (long long i = high; i >= low; --i) {
      if (a % i == 0 && b % i == 0) {
	find = true;
	cout << i << endl;
	break;
      }
    }
    if (!find) cout << "No answer" << endl;
  }
  return 0;
}
