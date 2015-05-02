// soj: 1766. 火柴棒等式
// Fri Dec 12, 2014--------Shawn Chow
// f(0) = 6, f(1) = 2, f(2) = 5, f(3) = 5, f(4) = 4
// f(5) = 5, f(6) = 6, f(7) = 3, f(8) = 7, f(9) = 6
#include "iostream"
using namespace std;

const int digit[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int match(int a) {
  int num = 0;
  do {
    num += digit[a % 10];
    a /= 10;
  } while (a);
  return num;
}

int main(int argc, char *argv[]) {
  int n, count;
  while (cin >> n) {
    count = 0;
    for (int i = 0; i < 750; ++i) {
      for (int j = 0; j < 750; ++j) {
	if (match(i) + match(j) + match(i + j) == n - 4) ++count;
      }
    }
    cout << count << endl;
  }
  return 0;
}

