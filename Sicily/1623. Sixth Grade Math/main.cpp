// soj: 1623. Sixth Grade Math
// Thu Dec 11, 2014--------Shawn Chow
#include "iostream"
using namespace std;

int GCF(int a, int b);
int LCM(int a, int b);
int main(int argc, char *argv[]) {
  int n, temp;
  cin >> n;
  temp = n;
  while (n--) {
    int a, b;
    cin >> a >> b;
    cout << temp - n << ' ' << LCM(a, b) << ' ' << GCF(a, b) << endl;
  }

  return 0;
}

int GCF(int a, int b) {
  int temp;
  while (a % b != 0) {
    temp = b;
    b = a % b;
    a = temp;
  }
  return b;
}

int LCM(int a, int b) {
  return a * b / GCF(a, b);
}
