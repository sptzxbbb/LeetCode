// soj: 3835. 计算三角形的周长
// Fri Dec 12, 2014--------Shawn Chow
#include "iostream"
#include "cmath"
using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  while (n--) {
    double x1, y1, x2, y2, x3, y3, length1, length2, length3, C;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    length1 = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    length2 = sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));
    length3 = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
    C = length1 + length2 + length3;
    cout.precision(5);
    cout << fixed << C << endl;
  }
  return 0;
}
