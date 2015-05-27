// soj: 4314. Coprime
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

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  while (n--) {
    int a, b;
    cin >> a >> b;
    if (GCD(a,b) == 1) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  return 0;
}
