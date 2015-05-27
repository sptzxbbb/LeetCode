// soj: 1634. Relax! It's just a game
// Fri Dec 12, 2014G--------Shawn Chow
#include "iostream"
using namespace std;

int main(int argc, char *argv[]) {
  int A, B, C;
  while (cin >> A >> B, A != -1 && B != -1) {
    C = A + B;
    int temp = C, combine = 1;
    while (temp >= C - A + 1) {
      combine *= temp;
      --temp;
    }

    temp = 1;
    while (temp <= A) {
      combine /= temp;
      ++temp;
    }

    if (combine == C) {
      cout << A << '+' << B << '=' << C << endl;
    } else {
      cout << A << '+' << B << "!=" << C << endl;
    }
  }
  return 0;
}

