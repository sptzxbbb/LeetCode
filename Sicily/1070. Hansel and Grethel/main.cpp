// soj: 1070. Hansel and Grethel
// Fri Dec 12, 2014--------Shawn Chow
#include "iostream"
#include "cmath"
using namespace std;

const double PI = 3.14159265;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  while (n--) {
    double x1, y1, angle1, x2, y2, angle2, k1, k2;
    // cin >> x1 >> y1 >> angle1;
    // cin >> x2 >> y2 >> angle2;

    // angle1 = 270 - angle1;
    // angle2 = 270 - angle2;

    // k1 = tan(angle1 * PI / 180.0);
    // k2 = tan(angle2 * PI / 180.0);
    k1 = tan(45.0 * PI / 180.0);
    k2 = tan(M_PI);
    cout << k1 << endl << k2 << endl;
  }
  return 0;
}
