// soj: 4315. Digit Count
// Thu Dev 11, 2014--------Shawn Chow
#include "iostream"
using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  while (n--) {
    int m, digit[10] = {0}, temp;
    cin >> m;
    for (int i = 1; i <= m; ++i) {
      temp = i;
      while (temp) {
	++digit[temp % 10];
	temp /= 10;
      }
    }
    for (int i = 0; i < 9; ++i) {
      cout << digit[i] << ' ';
    }
    cout << digit[9] << endl;
  }
  return 0;
}
