// soj: 1723. Reprogramming
// Fri Dec 12, 2014--------Shawn Chow
#include "iostream"
using namespace std;

int GCD(int a, int b) {
  int temp;
  while (a % b) {
    temp = b;
    b = a % b;
    a = temp;
  }
  return b;
}

// 42 56
// 42 / 56 = 0...42
// 56 / 42 = 1...14
// 42 / 14 = 3...0


int main(int argc, char *argv[]) {
  int x, y;
  while (cin >> x >> y, x != 0) {
    cout << GCD(x, y) << endl;
  }
  return 0;
}
