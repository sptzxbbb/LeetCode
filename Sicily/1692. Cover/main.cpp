// soj: 1692. Cover
// Tue Dec 16, 2014--------Shawn Chow
#include "iostream"
using namespace std;

int main(int argc, char *argv[]) {
  int a, b;
  while (cin >> a >> b, a != 0 && b != 0) {
    if (1 == a || 1 == b || a * b % 8 != 0) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
  return 0;
}
