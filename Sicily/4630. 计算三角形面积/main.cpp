// soj: 4630. 计算三角形面积
// Fri Dec 12, 2014--------Shawn Chow
#include "iostream"
#include "cmath"
using namespace std;

double area(double T[3][2]) {
  double s1, s2, s3, p, s;
  s1 = sqrt(pow(T[0][0] - T[1][0], 2) + pow(T[0][1] - T[1][1], 2));
  s2 = sqrt(pow(T[1][0] - T[2][0], 2) + pow(T[1][1] - T[2][1], 2));
  s3 = sqrt(pow(T[2][0] - T[0][0], 2) + pow(T[2][1] - T[0][1], 2));
  p = (s1 + s2 + s3) / 2;
  s = sqrt(p * (p - s1) * (p - s2) * (p - s3));
  return s;
}

int main(int argc, char *argv[]) {
  
  return 0;
}
