// soj: 1511. Conversion
// Thu Dec 11, 2014--------Shawn Chow
#include "iostream"
#include "string"
using namespace std;

int main(int argc, char *argv[]) {
  int n, m;
  string unit;
  double num;
  cin >> n;
  m = n;
  while (n--) {
    cin >> num >> unit;
    cout.precision(4);
    cout << fixed;
    if ("kg" == unit) {
      num *= 2.2046;
      unit = "lb";
    } else if ("l" == unit) {
      num *= 0.2642;
      unit = "g";
    } else if ("lb" == unit) {
      num *= 0.4536;
      unit = "kg";
    } else if ("g" == unit) {
      num *= 3.7854;
      unit = "l";
    }
    cout << m - n << ' ' << num << ' ' << unit << endl; 
  }

  return 0;
}
