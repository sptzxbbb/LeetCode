// soj: 1816. 平面几何问题
// Mon Dec, 1--------Shawn Chow
#include "cmath"
#include "iostream"
using namespace std;

const double pi = 3.141592653589793;
const double sqrt2 = 1.414213562373095;
const double sqrt3 = 1.732050807568877;

class Geometry {
public:
  
  Geometry(double r1 = 0, double r2 = 0) {
    m1 = r1;
    m2 = r2;
  }

  ~Geometry() {
    
  }

  double area() {
    if (0 == m2) {
      return m1 * m1 * pi;
    } else {
      return m1 * m2;
    }
  }

  double circumference() {
    if (0 == m2) {
      return 2 * pi * m1;
    } else {
      return 2 * (m1 + m2);
    }
  }

  double diagonal() {
    return sqrt2 * m1;
  }

private:
  double m1, m2;
};

int main(int argc, char *argv[]) {
  int t;
  cin >> t;
  while (t--) {
    double r;
    cin >> r;
    Geometry c1(r), s(2 * r, 2 * r), c2(sqrt2 * r);
    cout.precision(4);
    cout << fixed;
    cout << c1.area() << ' ' << c1.circumference() << endl;
    cout << s.area() << ' ' << s.circumference() << ' ' << s.diagonal() << endl;
    cout << c2.area() << ' ' << c2.circumference() << endl;
    cout << 6 * sqrt3 * r * r << ' ' << 6 * sqrt2 * sqrt3 * r << endl;
  }

  return 0;
}
