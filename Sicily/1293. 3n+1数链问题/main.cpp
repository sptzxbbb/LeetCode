// soj: 1293. 3n+1数链问题
// Sun Dec 7, 2014--------Shawn Chow
#include "iostream"
#include "cstring"
using namespace std;

const int MAX = 999999999;
int max_length = 0;

void chain(int a) {
  int length = 1;
  while (a != 1) {
    if (a % 2 == 1) {
      a = 3 * a + 1;
    } else {
      a /= 2;
    }
    length++;
  }
  if (max_length < length) max_length = length;
}

int main(int argc, char *argv[]) {
  int i, j;

  cin >> i >> j;
  for (int n = i; n <= j; ++n) {
     chain(n);
  }
  cout << max_length << endl;
  return 0;
}

