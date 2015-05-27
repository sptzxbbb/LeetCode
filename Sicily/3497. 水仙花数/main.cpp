// soj: 3497. 水仙花数
// Sun Nov 30, 2014--------Shawn Chow
#include "iostream"
using namespace std;

bool narci(int n);

int main(int argc, char *argv[]) {
  for (int i = 100; i < 1000; ++i) {
    if (narci(i)) cout << i << endl;
  }
  return 0;
}

bool narci(int n) {
  int a, b, c, temp = n;
  c = n % 10;
  n /= 10;
  b = n % 10;
  n /= 10;
  a = n % 10;
  return (temp == a * a * a + b * b * b + c * c * c);
}
