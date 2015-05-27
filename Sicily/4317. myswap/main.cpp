// soj: 4317. myswap
// Tue Dec 16, 2014--------Shawn Chow
#include "iostream"
using namespace std;

void myswap(int* p1, int* p2) {
  int temp;
  temp = *p1;
  *p1 = *p2;
  *p2 = temp;
}

int main(int argc, char *argv[]) {
  int a = 1, b = 2;
  myswap(&a, &b);
  cout << a << ' ' << b << endl;
  return 0;
}
