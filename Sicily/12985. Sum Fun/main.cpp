// soj: 12985. Sum Fun
// Thu Dec 25, 2014--------Shawn Chow
#include "iostream"
using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  while (n--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a + b == c) {
      cout << a << " + " << b << " = " << c << endl;
    } else if (a + c == b) {
      cout << a << " + " << c << " = " << b << endl;
    } else if (b + c == a) {
      cout << b << " + " << c << " = " << a << endl;
    } else {
      cout << a << ' ' << b << ' ' << c << " NO SUM" << endl;
    }
  }
  return 0;
}
