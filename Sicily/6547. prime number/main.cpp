// soj: 6547. prime number
// Tue Dec 16, 2014--------Shawn Chow
#include "iostream"
using namespace std;

bool prime(int a) {
  if (1 == a) return false;
  if (2 == a) return true;
  for (int i = 2; i * i <= a; ++i) {
    if (a % i == 0) return false;
  }
  return true;
}

int main(int argc, char *argv[]) {
  int n;
  while (cin >> n, n != -1) {
    if (prime(n)) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  return 0;
}

